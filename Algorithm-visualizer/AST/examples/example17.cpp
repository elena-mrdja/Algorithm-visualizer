#include "iostream"


int main(){
    //multiplication table
    int i = 1;
    int n = 7;
    double multiplication = 0;
    while(i<=10){
        multiplication = n * i;
        std::cout << n << " * " << i << " = " << multiplication << std::endl;
        i++;
    }
    return 0;
}