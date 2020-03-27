#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a){
    cin>>i;
  }
  sort(begin(a), end(a),[](const int& x, const int& y){
    if(x>0 && y>0){
      return x<y;
    } else if (x<0 && y>0){
      return -x<y;
    } else if (x>0 && y<0){
      return x<-y;
    } else if (x<0 && y<0){
      return x>y;
    }
  }
  );
  for (const auto& i : a){
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}

