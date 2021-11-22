#include "iostream"
int main(){
    int a = 2*4-(4/2);
    int b = 2*(4-4)/2;
    while (a != b) {
         std::cout << a << std::endl;
         a++;
    }
    return 0;
}
