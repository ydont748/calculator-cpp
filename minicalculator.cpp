#include <iostream>

int function = 0;
double a, b;

void print();

void loop();

void want();

void add();
void mainase();
void multibilation();
void devid();

int main() {
    
    print();

    return 0;
}

void print() {
    std:: cout << "What do you wnat me to calculate for you?" << std::endl;
    std:: cout << "1- add" << std::endl;
    std:: cout << "2- mainase" << std::endl;
    std:: cout << "3- multibilation" << std::endl;
    std:: cout << "4- devid" << std::endl;
    std:: cout << "5- nothing" << std::endl;
    std:: cin >> function;
    if (function != 5){
        std:: cout << "Enter your first number: " << std::endl;
        std:: cin >> a;
        std:: cout << "Enter your second number: " << std::endl;
        std:: cin >> b;
    }

    loop();
}

void loop() {
    switch (function)
    {
    case 1:
        add();
        break;
    case 2:
        mainase();
        break;
    case 3:
        multibilation();
        break;
    case 4:
        devid();
        break;
    
    default:
        std:: cout << "Goodbye!" << std::endl;
        break;
    }
}

void add() {
    double result = a + b;
    std:: cout << "The result is: " << result << std::endl;
    want();
}

void mainase() {
    double result = a - b;
    std:: cout << "The result is: " << result << std::endl;
    want();
}

void multibilation() {
    double result = a * b;
    std:: cout << "The result is: " << result << std::endl;
    want();
}

void devid() {
    if (b != 0) {
        double result = a / b;
        std:: cout << "The result is: " << result << std::endl;
    } else {
        std:: cout << "Error: Division by zero!" << std::endl;
    }
    want();
}

void want() {
    std:: cout << "Do you want to perform another calculation? (y/n): " << std::endl;
    char choice;
    std:: cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        print();
    } else {
        std:: cout << "Goodbye!" << std::endl;
    }
}