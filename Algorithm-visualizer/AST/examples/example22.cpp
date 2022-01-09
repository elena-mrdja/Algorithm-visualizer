#include "iostream"

int main(){
    // return if possible the n as the sum of two prime numbers
    int n = 7; 

    int i = 2;
    bool flag = false;

    while(i <= n/2) {
        int j =2;
        bool prime = true;
        while (j <= i/2){
            if (i%j == 0){
                prime =false;
                break;
            }
            j++;
        }
        if (prime == true){
            bool prime2 = true;
            if (n-i == 0 or n-i ==1){
                prime2=false;
            }
            else{
                int k =2;
                while(k<=(n-i)/2){
                    if ((n-i)%k == 0){
                        prime2 = false;
                        break;
                    }
                    k++;
                }
            }
            if (prime2 == true){
                std::cout << n << " = " << i << " + " << n-i << std::endl;
                flag = true;
                break;
            }
        }
      }

        if (!flag)
          std::cout << n << " can't be expressed as sum of two prime numbers." << std::endl;

        return 0;
}
