#include "iostream"


int main(){
    //return the prime numbers between two numbers
    int lowerbound = 61;
    int upperbound = 180;
    bool prime = true;
    while (lowerbound < upperbound) {
            prime = true;
            if (lowerbound == 0 or lowerbound == 1) {
                prime = false;
            }
            else {
                int j = 2;
                while(j <= lowerbound / 2) {
                    if (lowerbound % j == 0) {
                        prime = false;
                        break;
                    }
                    j++;
                }
            }
            if (prime){
                std::cout<<lowerbound<<std::endl;
            }
            ++lowerbound;
        }
}
