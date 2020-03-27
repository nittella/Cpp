#include <iostream>

using namespace std;

int main(){
    double n,a,b,x,y;
    cin>>n>>a>>b>>x>>y;
    double cost=n;
    if (n>b){
        cost = n*(100-y)/100;
    } else {
        if (n>a){
            cost = n*(100-x)/100;
        }
    }
    cout<<cost;

    return 0;
}