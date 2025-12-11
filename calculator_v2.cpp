#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <tuple>

int length;
int how_many;
int oper[6];
int ind = 0;
int count = 0;

bool errors(char inp[]);

struct node{
    public:
    double number;
    int operation;
    bool num;
    node* next = NULL;
    node* pre = NULL;
};

double change(char inp[]){
    // std::cout << "enter the change" << std::endl;
    double val = 0;
    for (size_t i = ind; i < length; i++){
        if (inp[i] >= 48 && inp[i] <= 57){
            val = val * 10;
            val = val + inp[i] - 48;
            // std::cout << "number loop ?" << std::endl;
        }else if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^' || inp[i] == '(' || inp[i] == ')'){
            ind = i;
            break;
        }
    }

    if (ind == length - 1){
        ind++;
    }
    
    // std::cout << "leave the change" << std::endl;
    return val;
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
        }else if(inp[i] == '('){
            then = 6;
            ind = i + 1;
            break;
        }else if(inp[i] == ')'){
            then = 7;
            ind = i + 1;
            break;
        }
    }

    return then;
}

std::tuple<double, int, bool> all(int the_count, node* the_start, node* the_end){
    for (size_t j = 0; j < 3; j++){
        node* tmp = the_start->next;
        for (size_t i = 0; i < the_count; i++){
            node* pre = tmp->pre;
            node* next = tmp->next;
            if (tmp->operation == 5 && j == 0){
                double num1 = pre->number;
                double num2 = next->number;
                double sum = pow(num1, num2);
                pre->number = sum;
                pre->next = next->next;
                if (next->next != NULL){
                    next->next->pre = pre;
                    tmp = next->next;
                }
            }else if(tmp->operation == 3 && j == 1){
                // std::cout << "here" << std::endl;
                double num1 = pre->number;
                double num2 = next->number;
                double sum = num1 * num2;
                pre->number = sum;
                pre->next = next->next;
                if (next->next != NULL){
                    next->next->pre = pre;
                    tmp = next->next;
                }
            }else if(tmp->operation == 4 && j == 1){
                double num1 = pre->number;
                double num2 = next->number;
                double sum = num1 / num2;
                pre->number = sum;
                pre->next = next->next;
                if (next->next != NULL){
                    next->next->pre = pre;
                    tmp = next->next;
                }
            }else if (tmp->operation == 2 && j == 2){
                double num1 = pre->number;
                double num2 = next->number;
                double sum = num1 - num2;
                pre->number = sum;
                pre->next = next->next;
                if (next->next != NULL){
                    next->next->pre = pre;
                    tmp = next->next;
                }
            }else if (tmp->operation == 1 && j == 2){
                // std::cout << "enter the 1" << std::endl;
                double num1 = pre->number;
                double num2 = next->number;
                double sum = num1 + num2;
                pre->number = sum;
                pre->next = next->next;
                if (next->next != NULL){
                    next->next->pre = pre;
                    tmp = next->next;
                }
                // std::cout << "wtf? " << std::endl;
            }
            if (tmp == the_end){
                break;
            }
        }
        // std::cout << "the count of the j: " << j << std::endl;
    }

    // std::cout << "the end of the for for loop " << std::endl;
    
    double n = the_start->number;
    int t = the_start->operation;
    bool s = the_start->num;
    
    // std::cout << "the n " << n << "the t " << t << "the s " << s << std::endl;

    return {n, t, s};
}

class BigLoad{
    public:
    int number;
    int start;
};

int main(){
    std::string input;
    
    std::cout << "Enter the qeustion: ";
    std::getline(std::cin, input);
    
    length = input.length();
    
    // char in[length + 1];

    char* in = new char[length + 1]; // Dynamic allocation
    std::strcpy(in, input.c_str());

    // std::vector<char> in(input.begin(), input.end());
    // in.push_back('\0');

    //int done[length + 1];

    // strcpy(in, input.c_str());
    
    // this part is to check for errors in the input
    bool error = errors(in);

    if (error == true){
        return 1;
    }

    node* head = NULL;
    node* tail = NULL;
    node* startnode = NULL;
    node* endnode = NULL;

    bool ifempty = true;
    bool doingsomething = false;
    int thelength = length;

    
    while(ind < thelength){
        // std::cout << "enter the loop " << std::endl;
        node* tmp= new node();
        if (in[ind] >= 48 && in[ind] <= 57){
            // std::cout << "enter the number " << std::endl;
            tmp->number = change(in);
            tmp->operation = 0;
            tmp->num = true;
            doingsomething = true;
            tmp->pre = tail;
            if (tail != NULL) {
                tail->next = tmp;
            } else {
                head = tmp; // If there is no tail, this is the first node (head)
            }
            // std::cout << "wtf ? " << std::endl;
            tail = tmp;
            count++;
            // std::cout << "leave the number " << std::endl;
        }else if (in[ind] == '+' || in[ind] == '-' || in[ind] == '*' || in[ind] == '/' || in[ind] == '^' || in[ind] == '(' || in[ind] == ')'){
            // std::cout << "enter the oper " << std::endl;
            tmp->number = 0;
            tmp->operation = looking(in);
            tmp->num = false;
            doingsomething = true;
            tmp->pre = tail;
            if (tail != NULL) {
                tail->next = tmp;
            } else {
                head = tmp; // If there is no tail, this is the first node (head)
            }
            tail = tmp;
            count++;
            // std::cout << "leave the oper " << std::endl;
        }else{
            ind++;
        }

        // std::cout << "come here " << std::endl;
        
        //i = ind;
        // std::cout << "what is the ind: " << ind << std::endl;
    }
    
    // std::cout << "it was here" << std::endl;

    int count_of_op = 0;
    while (oper[5] != 0){
        node* tmp = head;
        for (size_t i = 0; i < count; i++){
            if (tmp->operation == 6){
                startnode = tmp;
                count_of_op = 0;
            }else if(tmp->operation == 7){
                endnode = tmp;
                break;
            }else{
                count_of_op++;
            }
            tmp = tmp->next;
        }

        auto [n, t, s] = all(count_of_op, startnode, endnode);
        

        if (startnode->pre != NULL){
            startnode = startnode->pre;
        }
        startnode->number = n;
        startnode->operation = t;
        startnode->num = s;
        startnode->next = endnode->next;

        if (tail == endnode){
            tail = startnode;
        }
        
        oper[5] = oper[5] - 2;
        count = count - count_of_op - 2;
    }

    // std::cout << "after the loop" << std::endl;
    

    auto [sum, t, s] = all(count, head, tail);

    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}

bool errors(char inp[]){
    bool error = false;
    bool so = true;
    int count = 0;
    int op = 0;
    int num = 0;
    int prak_count = 0;
    bool number = true;
    bool prak = false;
    int count_6 = 0;
    int count_7 = 0;
    
    for (size_t i = 0; i < length; i++){
        if ((inp[i] >= 48 && inp[i] <= 57)){
            count = 0;
            number = true;
            prak = false;
            if((num + prak_count) - how_many == 0){
                num++;
            }
            if (so == true){
                op++;
                so = false;
            }
        }else if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^'){            
            number = false;
            count++;
            how_many++;
            so = true;
            prak = false;
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
            }
        }else if(inp[i] == '(' || inp[i] == ')'){
            prak = true;
            how_many++;
            prak_count++;
            oper[5]++;
            if (inp[i] == '('){
                count_6++;
            }else if (inp[i] == ')'){
                count_7++;
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
        
        if (how_many > (num + prak_count) && num == 0 && prak == false){
            std::cout << "Error: operation in the start " << inp[i] << std::endl;
            error = true;
        }else if (how_many == (num + prak_count) && i == length - 1 && prak == false){
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
    }else if(oper[5] % 2 != 0 || (count_6 != count_7)){
        std::cout << "Error: unbalanced parentheses" << std::endl;
        return true;
    }

    return false;
}