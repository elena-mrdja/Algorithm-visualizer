#include "iostream"


int main(){
    //find the GCD of a and b//
    int a = 181;
    int b= 69;
    while(a != b) {
        if(a > b){
          a -= b;
        }
        else {
          b -= a;
        }
      }
      std::cout << "GCD = " << a;

      return 0;
}
