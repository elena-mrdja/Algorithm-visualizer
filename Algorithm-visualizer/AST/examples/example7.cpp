#include "iostream"

int main(){
    int a = 2*4-(4/2);
    int b = 2*(4-4)/2;
    if (a==b) {
        std::cout << true << std::endl;
    }
    else {
        std::cout << false<< std::endl;
    }
    return 0;
}
