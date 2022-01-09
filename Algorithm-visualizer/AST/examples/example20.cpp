#include "iostream"

int main(){
    //function that return the number of vowels, of consonants, of digits and of spaces in a string

    char line[150]= "The project number 1 is this one.";     //Example of string
    int num =32;                                             //Size of the string

    int vowels=0;
    int consonants=0;
    int digits=0;
    int spaces=0;
    int i = 0;
    while(i < num) {
       if(line[i]=='a' or line[i]=='e' or line[i]=='i' or line[i]=='o' or line[i]=='u' or line[i]=='A' or line[i]=='E'
          or line[i]=='I' or line[i]=='O' or line[i]=='U'){
            vowels++;
            i++;
        }
        else if((line[i]>='a' and line[i]<='z') || (line[i]>='A' and line[i]<='Z')){
            consonants++;
            i++;
        }
        else if(line[i]>='0' and line[i]<='9'){
            digits++;
            i++;
        }
        else if (line[i]==' '){
            spaces++;
            i++;
        }
    }

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
    std::cout << "Digits: " << digits << std::endl;
    std::cout << "White spaces: " << spaces << std::endl;

    return 0;
}