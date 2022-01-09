#include "iostream"


int main(){
    //test strict inequalities and ++, --//
    int a = 2*4-(4/2);
    int b = 2*(4-4)/2;
    if (a < b){
        a++;
        std::cout << a << std::endl;
    }
    else if (a > b){
        a--;
        std::cout << a << std::endl;
    }
    else {
        std::cout << "they are equal" << std::endl;
    }
    return 0;
}

