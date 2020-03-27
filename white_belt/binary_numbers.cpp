#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a;
    cin>>a;
    vector<int> v;
    if (a==0){
        cout<<0;
    }
    else{
        while (a!=1){
            v.push_back(a%2);
            a/=2;
        }
        v.push_back(a);
        for (int i = v.size()-1; i!=-1; i--){
            cout<<v[i];
        }
    }



    return 0;
}