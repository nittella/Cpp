#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    char letter = 'f';
    int i = -2;
    for (int j=0; j<=s.size(); j++){
        if (s[j]==letter){
            if (i==-2){
                i=-1;
            } else{
                i=j;
                break;
            }
        }

    }
    cout<<i;

    return 0;
}