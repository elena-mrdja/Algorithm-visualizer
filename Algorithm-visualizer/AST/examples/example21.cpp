#include "iostream"

int main(){
    //function that return the of a character in a string
    char str[150] = "C++ Programming is awesome";   //Example of string
    int n = 27;                                     //Size of the string
    char Character = 'm';                      //Character

    int count = 0;
    int i =0;

    while (i < n){
        if (str[i] == Character){
           count++;
        }
        i++;
    }
    std::cout << count << std::endl;

    return 0;
}