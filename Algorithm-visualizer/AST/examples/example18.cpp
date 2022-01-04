#include "iostream"


int main(){
    //Compute power of a number x^n
    double x = 6;
    int n = 4;
    double result = 1;
    while(n!=0){
        result=result*x;
        n--;
    }
    return result;
}
