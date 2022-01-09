#include "iostream"


int main(){
    // return the reversed numbe, i.e if n = abcd, then reverse = dcba
    int n = 8154;
    int reverse = 0;
    int remainder = 0;
    while(n!=0){
        remainder = n%10;
        reverse = reverse*10 + remainder;
        n /= 10;
    }
    return reverse;
}