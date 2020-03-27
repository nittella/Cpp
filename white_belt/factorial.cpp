#include <iostream>

using namespace std;

int Factorial(int x){
    int factorial = 1;
    if (x>0){
        for (int i=2; i<=x; i++){
            factorial*=i;
        }
    }
    return factorial;

}

int main(){
    cout<<Factorial(0);

    return 0;
}