#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    int i;
    if (a%2==0){
        i=a;
    }else {
        i=++a;
    }
    while(i<=b){
        cout<<i<<" ";
        i+=2;
    }


    return 0;
}