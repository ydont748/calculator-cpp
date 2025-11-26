import React, { useState, useCallback, useMemo } from 'react';

// --- Configuration and Initial Data ---
const DEFAULT_PIN = '1234';
const INITIAL_BALANCE = 500.00;

// Utility function to format currency
const formatCurrency = (amount) => {
  return new Intl.NumberFormat('en-US', {
    style: 'currency',
    currency: 'USD',
  }).format(amount);
};

// Component for a styled button
const Button = ({ onClick, children, className = '', disabled = false }) => (
  <button
    onClick={onClick}
    disabled={disabled}
    className={`w-full py-3 px-4 rounded-xl font-semibold transition duration-200 
                ${disabled
                  ? 'bg-gray-400 text-gray-700 cursor-not-allowed'
                  : 'bg-indigo-600 hover:bg-indigo-700 text-white shadow-lg shadow-indigo-500/50'
                } ${className}`}
  >
    {children}
  </button>
);

// --- 1. Login Screen Component ---
const LoginScreen = ({ onLoginSuccess }) => {
  const [pinInput, setPinInput] = useState('');
  const [attempts, setAttempts] = useState(3);
  const [error, setError] = useState('');

  const handlePinChange = (e) => {
    const value = e.target.value.replace(/[^0-9]/g, '').slice(0, 4);
    setPinInput(value);
    setError('');
  };

  const handleLogin = () => {
    if (pinInput === DEFAULT_PIN) {
      onLoginSuccess();
    } else {
      setAttempts(attempts - 1);
      setError(`Invalid PIN. ${attempts - 1} attempts remaining.`);
      setPinInput('');
      if (attempts - 1 <= 0) {
        setError("ATM is locked. Please contact bank support.");
      }
    }
  };

  return (
    <div className="space-y-6">
      <h2 className="text-3xl font-bold text-center text-gray-800">Welcome</h2>
      <p className="text-center text-gray-500">Please enter your 4-digit PIN.</p>
      
      <input
        type="password"
        maxLength="4"
        value={pinInput}
        onChange={handlePinChange}
        disabled={attempts <= 0}
        className="w-full text-center p-4 text-3xl tracking-[1.5rem] bg-gray-100 rounded-xl focus:ring-4 focus:ring-indigo-500 transition border-2 border-gray-300"
      />

      {error && <p className="text-center text-red-500 font-medium">{error}</p>}
      
      <Button 
        onClick={handleLogin} 
        disabled={pinInput.length !== 4 || attempts <= 0}
      >
        Login
      </Button>
      <p className="text-xs text-center text-gray-400">Hint: PIN is {DEFAULT_PIN}</p>
    </div>
  );
};

// --- 2. Main Menu Component ---
const MainMenu = ({ onSelectView, onLogout }) => (
  <div className="space-y-4">
    <h2 className="text-3xl font-bold text-center text-gray-800">ATM Services</h2>
    <Button onClick={() => onSelectView('balance')}>Check Balance</Button>
    <Button onClick={() => onSelectView('deposit')} className="bg-green-600 hover:bg-green-700 shadow-green-500/50">Deposit Funds</Button>
    <Button onClick={() => onSelectView('withdraw')} className="bg-orange-600 hover:bg-orange-700 shadow-orange-500/50">Withdraw Cash</Button>
    <Button onClick={onLogout} className="bg-gray-500 hover:bg-gray-600 shadow-none">Exit & Logout</Button>
  </div>
);

// --- 3. Transaction Screen Component (Deposit/Withdraw) ---
const TransactionScreen = ({ type, balance, onTransaction, onBack }) => {
  const [amountInput, setAmountInput] = useState('');
  const [error, setError] = useState('');

  const isWithdraw = type === 'withdraw';
  const title = isWithdraw ? 'Cash Withdrawal' : 'Cash Deposit';
  const actionText = isWithdraw ? 'Withdraw' : 'Deposit';

  const handleAmountChange = (e) => {
    const value = e.target.value.replace(/[^0-9.]/g, ''); // Allow only numbers and one decimal point
    setAmountInput(value);
    setError('');
  };

  const handleSubmit = () => {
    const amount = parseFloat(amountInput);
    if (isNaN(amount) || amount <= 0) {
      setError('Please enter a valid positive amount.');
      return;
    }

    if (isWithdraw) {
      if (amount > balance) {
        setError('Insufficient Funds. Cannot withdraw more than your balance.');
        return;
      }
      if (amount % 10 !== 0) {
        setError('Withdrawals must be in multiples of 10.');
        return;
      }
    }
    
    onTransaction(amount, isWithdraw);
    setAmountInput('');
  };

  return (
    <div className="space-y-6">
      <h2 className="text-2xl font-bold text-center text-gray-800 border-b pb-3">{title}</h2>
      <div className="text-center text-lg">
        <p className="text-gray-500">Current Balance</p>
        <p className="text-4xl font-extrabold text-indigo-600">{formatCurrency(balance)}</p>
      </div>

      <input
        type="text"
        value={amountInput}
        onChange={handleAmountChange}
        placeholder="Enter amount"
        className="w-full text-center p-4 text-2xl bg-white border-2 border-indigo-200 rounded-xl focus:ring-4 focus:ring-indigo-500 transition"
      />

      {error && <p className="text-center text-red-500 font-medium">{error}</p>}
      
      <Button onClick={handleSubmit}>{actionText}</Button>
      <Button onClick={onBack} className="bg-gray-300 hover:bg-gray-400 text-gray-800 shadow-none">Back to Menu</Button>
    </div>
  );
};

// --- 4. Balance Screen Component ---
const BalanceScreen = ({ balance, onBack }) => (
  <div className="space-y-6">
    <h2 className="text-3xl font-bold text-center text-gray-800">Account Balance</h2>
    <div className="bg-indigo-50 p-8 rounded-xl shadow-inner border border-indigo-200">
      <p className="text-center text-xl text-gray-600">Your Current Balance Is:</p>
      <p className="text-6xl font-extrabold text-center text-indigo-700 mt-2">
        {formatCurrency(balance)}
      </p>
    </div>
    <Button onClick={onBack}>Back to Menu</Button>
  </div>
);


// --- Main Application Component ---
const App = () => {
  const [isAuthenticated, setIsAuthenticated] = useState(false);
  const [balance, setBalance] = useState(INITIAL_BALANCE);
  const [currentView, setCurrentView] = useState('login'); // 'login', 'menu', 'balance', 'deposit', 'withdraw'
  const [message, setMessage] = useState('');

  // Function to handle a successful transaction
  const handleTransaction = useCallback((amount, isWithdraw) => {
    let newBalance;
    if (isWithdraw) {
      newBalance = balance - amount;
      setMessage(`✅ Withdrawal Successful! You took out ${formatCurrency(amount)}.`);
    } else {
      newBalance = balance + amount;
      setMessage(`✅ Deposit Successful! You added ${formatCurrency(amount)}.`);
    }
    setBalance(newBalance);
    setCurrentView('menu');

    // Clear message after a few seconds
    setTimeout(() => setMessage(''), 5000);
  }, [balance]);

  // Handle successful login
  const handleLoginSuccess = useCallback(() => {
    setIsAuthenticated(true);
    setCurrentView('menu');
  }, []);

  // Handle logout
  const handleLogout = useCallback(() => {
    setIsAuthenticated(false);
    setCurrentView('login');
    setMessage('You have successfully logged out.');
  }, []);

  // Render the current screen based on authentication and view state
  const renderScreen = useMemo(() => {
    if (!isAuthenticated) {
      return <LoginScreen onLoginSuccess={handleLoginSuccess} />;
    }

    switch (currentView) {
      case 'menu':
        return (
          <MainMenu 
            onSelectView={setCurrentView} 
            onLogout={handleLogout} 
          />
        );
      case 'balance':
        return (
          <BalanceScreen 
            balance={balance} 
            onBack={() => setCurrentView('menu')} 
          />
        );
      case 'deposit':
      case 'withdraw':
        return (
          <TransactionScreen
            type={currentView}
            balance={balance}
            onTransaction={handleTransaction}
            onBack={() => setCurrentView('menu')}
          />
        );
      default:
        return <p className="text-red-500">Error: Invalid View State</p>;
    }
  }, [isAuthenticated, currentView, balance, handleLoginSuccess, handleLogout, handleTransaction]);

  return (
    <div className="min-h-screen bg-gray-50 flex items-center justify-center p-4 font-sans">
      <script src="https://cdn.tailwindcss.com"></script>
      <div className="w-full max-w-md bg-white p-8 sm:p-10 rounded-3xl shadow-2xl border-t-8 border-indigo-600 transition-all duration-300">
        
        {/* Success Message Banner */}
        {message && (
          <div className="mb-6 p-4 bg-green-100 border-l-4 border-green-500 text-green-700 rounded-lg" role="alert">
            <p className="font-bold">System Alert</p>
            <p>{message}</p>
          </div>
        )}

        {/* Dynamic Screen Rendering */}
        {renderScreen}
        
      </div>
    </div>
  );
};

export default App;
