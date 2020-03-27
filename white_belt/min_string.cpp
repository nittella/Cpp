#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b, c;
    cin>>a>>b>>c;
    if (!a.empty() && a<b && a<c){
        cout<<a;
    }else {
        if (!b.empty() && b<c){
            cout<<b;
        } else {
            cout<<c;
        }

    }

    return 0;
}

