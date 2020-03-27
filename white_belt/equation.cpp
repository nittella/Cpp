#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c,d;
    cin>>a>>b>>c;
    d = b*b-4*a*c;
        if (a==0){
            if (b!=0){
                double x_lin = -c/b;
                cout<<x_lin;
            }

    }else{
        if (d>0){
            double x1=(-b+sqrt(d))/2/a;
            double x2=(-b-sqrt(d))/2/a;
            cout<<x1<<" "<<x2;
        } else{
            if (d==0){
                double x = (-b)/2/a;
                cout<<x;
            }
        }
    }
    return 0;
}