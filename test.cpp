#include <iostream>

int main(){

    char ca[] = {'5','5','3','1'};
    int num = 3;

    while (ca[num] != '5' && num > 2){
        std::cout << "number " << ca[num] << std::endl;
        num--;
    }
    
    std::cout << "num " << num << std::endl;
    
    int sum = num + ca[0] - 48;

    //std::cout << sum;

    

    return 0;
}