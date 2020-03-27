#include <iostream>
#include <vector>
#include <string>

using namespace std;

void UpdateIfGreater(const int& first, int& second){
    if(first>second){
        second=first;
    }
}
int main(){
    int a = 4;
    int b = 6;
    UpdateIfGreater(a, b);
    cout<<a<<" "<<b;

    return 0;
}