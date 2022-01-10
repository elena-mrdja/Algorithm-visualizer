#include "iostream"


int main(){
    //returns whether or not n is prime
    int n = 31;
    int i = 2;
    bool prime = true;
    if (n == 0 or n == 1) {
        prime = false;
    }
    else {
        while (i<=n/2) {
            if (n % i == 0) {
              prime = false;
              break;}
            i ++;
        }
    }
    if (prime){
        std::cout << n << " is a prime number" << std::endl ;
    }
    else{
        std::cout << n << " is not a prime number" << std::endl ;
    }
    return 0;
}
