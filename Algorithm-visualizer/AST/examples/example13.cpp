#include "iostream"


int main(){
    //continue test//
    int i = 0;
    while (i < 10) {
      if (i == 4) {
        i++;
        continue;
      }
      std::cout << i << "\n";
      i++;
    }
    return 0;
}