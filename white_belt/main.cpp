
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int FindGCF1 (int a, int b){
  while (a > 0 && b > 0) {
    // возьмём большее из чисел и заменим его остатком от деления на второе
    // действительно, если a и b делятся на x, то a - b и b делятся на x
    // тогда и a % b и b делятся на x, так что можно a заменить на a % b
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  // если одно из чисел оказалось равно нулю, значит, на последней итерации
  // большее число разделилось на меньшее
  return a + b;
}
int FindGCF2 (const int& x, const int& y){
  int a,b;
  int result;
  if(x<y){
    a=x;
    b=y;
  }  else {
    a=y;
    b=x;
  }
  int j=2;
  bool n= false;
  for (int i=1; i<=j;i++){
    j=a/i;
    if (a%j==0 && b%j==0){
      result = j;
      n=true;
      break;
    }
  }
  if(!n){
    result = 1;
  }
  return result;
}

int main(){

  int  r1 = FindGCF1(14,-7);
  int  r2 = FindGCF2(14,-7);
  cout << "FindGCF1: " << r1 << endl;
  cout << "FindGCF2: " << r2 << endl;


  return 0;
}