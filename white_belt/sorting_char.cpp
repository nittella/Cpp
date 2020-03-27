#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);

  for (auto& s : a) {
    cin>>s;
  }
  sort(begin(a), end(a),[](const string& x, const string& y){
    string x_tmp=x;
    string y_tmp=y;
    for (int i = 0; i<x_tmp.size();i++){
      x_tmp[i]=tolower(x_tmp[i]);
    }
      for (int i = 0; i<y_tmp.size();i++){
        y_tmp[i]=tolower(y_tmp[i]);
      }
      return x_tmp<y_tmp;
  });
  for (const auto& i : a){
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}