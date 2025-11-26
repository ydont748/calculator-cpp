#include <iostream>

int main(){
    int cubes = 0;
    std::cin >> cubes;

    int level = 0;
    int sum = 0;
    int plus = 0;

    for (size_t i = 1; i <= cubes; i++){
        plus += i;
        sum += plus;
        
        if (sum > cubes){
            break;
        }
        level++;
    }

    std::cout << level << std::endl;
}