#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

int end_end;
int start_end;
int start_start;
int end_start;
int from;
int length;
int how_many = 0;
int oper[6];
int ind = 0;
bool divi_zero = false;

/*
    i want to make an array that have how many operation that i have so i know that i finish this operation or not 
    i can make that array have the sum of the operation 
    i can make another array to have the value of the number 

*/

/*
    i want to make an array that have all the operation that i have then i want to write a number for each operation like if it was + i write 1 or if it was - i write 2
    this way when i want to do the operation i start from the start and i see the next index was is the operation then i deside whice one i do first 
*/

bool errors(char inp[]);

void knowing(char inp[], int here);


/*
void multiply(int first, int second){
    return first * second;
}

void division(int first, int second){
    return first / second;
}

int plus(int first, int second){
    return first + second;
}

int substract(int first, int second){
    return first - second;
}
*/

double change(char inp[]);

int looking(char inp[]);

double four(double first, double second){
    return first / second;
}

void sort_op(int here){
    for (int i = here; i < how_many; i++){
        oper[i] = oper[i + 1];
    }
}

void sort_num(int here, double numbers[], int sum){
    numbers[here] = sum;
    for (int i = here + 1; i < how_many; i++){
        numbers[i] = numbers[i + 1];
    }
    how_many--;
}

double idk(double numbers[], int oper[]){
    double all_sum = numbers[0];
    double sec_sum = 0;
    int other = 0;

    for (int j = 3; j > 0; j--){
        for (int i = how_many - 1; i >= 0; i--){
            // std::cout << "enter loop " << i << std::endl;
            //std::cout << "oper  " << oper[i] << std::endl;
            // std::cout << "how many  " << how_many << std::endl;
            if(oper[i] == 5 && j == 3){
                numbers[i] = pow(numbers[i], numbers[i + 1]);
                for (int k = i; k < how_many; k++){
                    oper[k] = oper[k + 1];
                }
                for (int k = i + 1; k < how_many; k++){
                    numbers[k] = numbers[k + 1];
                }
                how_many--;
            }else if(oper[i] == 4 || oper[i] == 3 && j == 2){
                // std::cout << "enter if statment" << std::endl; 
                int tail = i;
                while ((oper[i - 1] == 4 || oper[i - 1] == 3) && i >= 0){
                    i--;
                    // std::cout << "the loop " << i << std::endl; 
                }
                int head = i;
                int here = head;
                
                double sum;

                sum = numbers[head];
                head++;
                while (here != tail + 1){
                    int sec = numbers[head];
                    if (oper[i] == 3){
                        sum = sum * sec;
                    }else{
                        sum = sum / sec;
                    }
                    
                    for (int i = here; i < how_many; i++){
                        oper[i] = oper[i + 1];
                    }
                    
                    numbers[here] = sum;
                    
                    for (int i = here + 1; i < how_many; i++){
                        numbers[i] = numbers[i + 1];
                    }
                    how_many--;
                    tail--;
                }
            }else if((oper[i] == 1 || oper[i] == 2) && j == 1){
                int tail = i;
                while ((oper[i - 1] == 1 || oper[i - 1] == 2) && i >= 0){
                    i--;
                    // std::cout << "the loop " << i << std::endl;
                }
                int head = i;
                int here = head;

                double sum;
                
                sum = numbers[head];
                head++;
                while (here != tail + 1){
                    int sec = numbers[head];
                    if (oper[i] == 1){
                        // std::cout << "sec " << sec << std::endl;
                        sum = sum + sec;
                        // std::cout << "+ " << sum << std::endl;
                    }else{
                        sum = sum - sec;
                    }
                    
                    for (int i = here; i < how_many; i++){
                        oper[i] = oper[i + 1];
                    }
                    
                    numbers[here] = sum;
                    
                    for (int i = here + 1; i < how_many; i++){
                        numbers[i] = numbers[i + 1];
                    }
                    how_many--;
                    tail--;
                    // std::cout << "tail " << tail << std::endl;
                
                }
            }
        }
    }

    return numbers[0];
}

double agwas(double numbers[], int oper[]){
    return 0;
}

double all(double numbers[], int oper[]){
    double all_sum = numbers[0];
    double sec_sum = 0;

    for (size_t i = 0; i < how_many; i++){
        sec_sum = 0;
        std::cout << "the oper: " << oper[i] << std::endl;
        std::cout << "the oper + 1: " << oper[i + 1] << std::endl;

        if (oper[i] == 5){
            // the function
        }else if(oper[i] == 4){
            if (oper[i + 1] == 5 && i != how_many - 1){
                int now = i + 1;
                while (oper[now] == 5 && now != - 1){
                    now++;
                }
                while (now != i + 1){
                    // the function
                    // sec_sum
                    oper[now] == 0;
                    now--;
                }
            }else{
                sec_sum = numbers[i + 1];
            }

            if(sec_sum == 0){
                divi_zero = true;
                return 1;
            }else{
                all_sum = all_sum / sec_sum;
            }
        }else if(oper[i] == 3){
            if (oper[i + 1] == 5){
                int now = i + 1;
                while (oper[now] == 5){
                    now++;
                }
                while (now != i + 1){
                    // the function
                    // sec_sum
                    oper[now] == 0;
                    now--;
                }
            }else{
                sec_sum = numbers[i + 1];
            }
            all_sum = all_sum * sec_sum;
        }else if (oper[i] == 2){
            sec_sum = 1;
            double second = 0;
            int third = 0;
            if ((oper[i + 1] == 5 || oper[i + 1] == 4 || oper[i + 1] == 3) && i < how_many - 1){
                int now = i + 1;
                int sq = 0;
                second = numbers[now + 2];
                third = numbers[now + 1];
                //std::cout << "first" << std::endl;
                while ((oper[now] == 5 || oper[now] == 4 || oper[now] == 3) && now < how_many - 1){
                    if (oper[now] == 5){
                        while (oper[now] == 5){
                            now++;
                        }
                        sq = now;
                        while (oper[now] == 5){
                            if (oper[now] == 5){
                                // do the function
                                // second
                            }
                            oper[now] = 0;
                            now--;
                        }
                        int point = now;
                        sec_sum = numbers[now];
                        while (now != point - 1){
                            if (oper[now] == 4){
                                // do the function
                                if (numbers[now + 1] == 0){
                                    divi_zero = true;
                                    return 1;
                                }else{
                                    sec_sum = sec_sum / numbers[now + 1];
                                }   
                            }else{
                                // do the function
                                sec_sum = sec_sum * numbers[now + 1];
                            }
                            now++;
                        }


                        if (numbers[now + 1] == 4){
                            sec_sum = sec_sum / second;
                        }else{
                            sec_sum = sec_sum * second;
                        }
                        now = sq;
                    }else{
                        second = numbers[now + 2];
                    }
                    
                    now++;
                }
                
                //std::cout << "now " << now << std::endl;
                int again = now;
                now = i + 1;

                while (now < again){
                    //std::cout << "second" << std::endl;
                    if (oper[now] == 4){
                        // do the function
                        if (numbers[now + 1] == 0){
                            divi_zero = true;
                            return 1;
                        }else{
                            sec_sum = sec_sum / numbers[now + 1];
                        }
                    }else{
                        // do the function
                        //std::cout << "third" << std::endl;
                        //std::cout << "sec_sum: " << sec_sum << std::endl;
                        sec_sum = sec_sum * numbers[now + 1];
                        // std::cout << "sec_sum: " << sec_sum << std::endl;
                    }
                    oper[now] = 0;
                    now++;
                }
                
                // std::cout << "second: " << second << std::endl;

                
                if (oper[again] == 4){
                    sec_sum = sec_sum / second;
                }else{
                    // std::cout << "fourth" << std::endl;
                    sec_sum = sec_sum * second;
                }
                
                oper[again] = 0;
                // std::cout << "sec_sum: " << sec_sum << std::endl;
                
                // std::cout << "fivth" << std::endl;
                all_sum = all_sum - sec_sum;

            }else{
                all_sum = all_sum - numbers[i + 1];
            }
        }else if(oper[i] == 1){
            sec_sum = 1;
            double second = 0;
            if ((oper[i + 1] == 5 || oper[i + 1] == 4 || oper[i + 1] == 3) && i < how_many - 1){
                int now = i + 1;
                int sq = 0;
                second = numbers[now + 1];
                while ((oper[now] == 5 || oper[now] == 4 || oper[now] == 3) && now < how_many - 1){
                    if (oper[now] == 5){
                        while (oper[now] == 5){
                            now++;
                        }
                        sq = now;
                        while (oper[now] == 5){
                            if (oper[now] == 5){
                                // do the function
                                // second
                            }
                            oper[now] = 0;
                            now--;
                        }
                        int point = now;
                        sec_sum = numbers[now];
                        while (now != point - 1){
                            if (oper[now] == 4){
                                // do the function
                                if (numbers[now + 1] == 0){
                                    divi_zero = true;
                                    return 1;
                                }else{
                                    sec_sum = sec_sum / numbers[now + 1];
                                }   
                            }else{
                                // do the function
                                sec_sum = sec_sum * numbers[now + 1];
                            }
                            now++;
                        }

                        if (numbers[now + 1] == 4){
                            sec_sum = sec_sum / second;
                        }else{
                            sec_sum = sec_sum * second;
                        }
                        now = sq;
                    }else{
                        second = numbers[now + 2];
                        //std::cout << "number[now + 2]: " << numbers[now + 2] << std::endl;
                    }
                    now++;
                }

                std::cout << "now: " << now << std::endl;

                int again = now;
                now = i + 1;

                while (now < again){
                    if (oper[now] == 4){
                        // do the function
                        if (numbers[now + 1] == 0){
                            divi_zero = true;
                            return 1;
                        }else{
                            sec_sum = sec_sum / numbers[now + 1];
                            oper[now] = 0;
                        }
                    }else{
                        // do the function
                        sec_sum = sec_sum * numbers[now + 1];
                        oper[now] = 0;
                    }
                    now++;
                }

                if (oper[again] == 4){
                    sec_sum = sec_sum / second;
                    oper[again] = 0;
                }else{
                    sec_sum = sec_sum * second;
                    oper[again] = 0;
                }


                all_sum = all_sum + sec_sum;
            }else{
                all_sum = all_sum + numbers[i + 1];
            } 
        }
    }

    return all_sum;
}

int main(){
    std::string input;
    
    std::cout << "Enter the qeustion: ";
    std::getline(std::cin, input);
    
    length = input.length();
    
    char in[length + 1];
    int done[length + 1];

    strcpy(in, input.c_str());
    
    bool error = errors(in);
    
    if (error == true){
        return 1;
    }

    double value[how_many + 1];
    int the[how_many];
    
    for (size_t i = 0; i < how_many + 1; i++){
        value[i] = change(in);
    }
    
    ind = 0;

    for (size_t i = 0; i < how_many; i++){
        the[i] = looking(in);
        // std::cout << "the oper is: " << the[i] << std::endl;
    }

    double sum;

    /*
    for (int i = 1; i < 4; i++){
        double sum = sec_idk(value, the, i);
    }
    */
    
    //std::cout << "the sum is: " << sum << std::endl;

    //double sum = all(value, the); 
    sum = idk(value, the); 
    
    std::cout << "the sum is: " << sum << std::endl;
    
    
    /*
    for (int i = 0; i < length; i++) {
        if ((in[i] < 48 || in[i] > 57) && in[i] != ' '){
            knowing(in, i, length);
            std::cout << "the " << in[i] << " operation start at " << end_start << " the end at " << end_end << std::endl;
        }
    }
            
    */

    return 0;
}

int looking(char inp[]){
    int then = 0;
    for (size_t i = ind; i < length; i++){
        if (inp[i] == '+'){
            then = 1;
            ind = i + 1;
            break;
        }else if(inp[i] == '-'){
            then = 2;
            ind = i + 1;
            break;
        }else if(inp[i] == '*'){
            then = 3;
            ind = i + 1;
            break;
        }else if(inp[i] == '/'){
            then = 4;
            ind = i + 1;
            break;
        }else if(inp[i] == '^'){
            then = 5;
            ind = i + 1;
            break;
        }
    }

    return then;
}

double change(char inp[]){
    int val = 0;
    for (size_t i = ind; i < length; i++){
        if (inp[i] >= 48 && inp[i] <= 57){
            val = val * 10;
            val = val + inp[i] - 48;
        }else if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^'){
            ind = i + 1;
            break;
        }
    }

    return val;
}

bool errors(char inp[]){
    bool error = false;
    bool so = true;
    int count = 0;
    int op = 0;
    int num = 0;
    bool number = true;
    
    for (size_t i = 0; i < length; i++){
        if ((inp[i] >= 48 && inp[i] <= 57)){
            count = 0;
            number = true;
            if(num - how_many == 0){
                num++;
            }
            if (so == true){
                op++;
                so = false;
            }
        }else if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^' || inp[i] == '(' || inp[i] == ')'){            
            number = false;
            count++;
            how_many++;
            so = true;
            op = 0;
            if (inp[i] == '+'){
                oper[0]++;
            }else if (inp[i] == '-'){
                oper[1]++;
            }else if (inp[i] == '-'){
                oper[1]++;
            }else if (inp[i] == '*'){
                oper[2]++;
            }else if (inp[i] == '/'){
                oper[3]++;
            }else if (inp[i] == '^'){
                oper[4]++;
            }else if (inp[i] == '(' || inp[i] == ')'){
                oper[5]++;
            }
        }else if(inp[i] == ' '){
            if (so == false){
                op++;
                so = true;
            }
        }else{
            std::cout << "Error: Invalid character " << inp[i] << std::endl;
            error = true;
        }
        
        if (how_many > num && num == 0){
            std::cout << "Error: operation in the start " << inp[i] << std::endl;
            error = true;
        }else if (how_many == num && i == length - 1){
            std::cout << "Error: operation in the end " << inp[i] << std::endl;
            error = true;
        }else if (number == false && count >= 2){
            std::cout << "Error: Consecutive operators " << inp[i] << std::endl;
            error = true;
            count = 1;
        }else if(op == 3){
            std::cout << "No operation here: index[" << i << "]" << std::endl;
            op = 0;
            error = true;
        }
    }

    if (error == true){
        return true;
    }else if(oper[5] % 2 != 0){
        std::cout << "Error: unbalanced parentheses" << std::endl;
        return true;
    }

    return false;
}

void knowing(char inp[], int here){
    start_end = 0;
    end_end = 0;
    start_start = length;
    end_start = length;
    int count = 0;
    bool count_end = false;
    bool count_start = false;

    for (size_t i = 1; i < length; i++){
        if (end_end == 0 && (here + i <= length)){
            if (inp[here + i] >= 48 && inp[here + i] <= 57){
                count_end = true;
                start_end = here + i;
            }else if((inp[here + i] == '+' || inp[here + i] == '-' || inp[here + i] == '*' || inp[here + i] == '/' || inp[here + i] == '^' || inp[here + i] == ' ') && count_end == true){
                end_end = here + i - 1;
                count++;
            }
        }
        if (end_start == length && (here - i >= 0)){
            if (inp[here - i] >= 48 && inp[here - i] <= 57){
                count_start = true;
                start_start = here - i;
            }else if((inp[here - i] == '+' || inp[here - i] == '-' || inp[here - i] == '*' || inp[here - i] == '/' || inp[here - i] == '^' || inp[here - i] == ' ') && count_start == true){
                end_start = here - i + 1;
                count++;
            }
        }
        if (count == 2 || (here - i <= 0 && here + i >= length)){
            break;
        } 
    }
    
    if(end_end == 0){
        end_end = length - 1;
    }

    if(end_start == length){
        end_start = 0;
    }
}