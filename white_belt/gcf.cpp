#include <iostream>


using namespace std;

int main(){
     int x, y;
     cin>>x>>y;
     int a,b;
  if(x<y){
    a=x;
    b=y;
  }
  else {
    a=y;
    b=x;
  }
  int j=2;
  bool n= false;
  for (int i=1; i<=j;i++){
    j=a/i;
    if (a%j==0 && b%j==0){
      cout<<j;
      n=true;
      break;
    }

  }
  if(!n){
    cout<<1;
  }
  return  0;
}