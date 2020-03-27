#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v){
  bool is_first = true;
  for (auto i : v){
    if (!is_first){
      os << " ";
    }
    os << i;
    is_first = false;
  }
  return os;
}

int main(){
  int n;
  cin >> n;

  vector<int> v(n, 0);
  iota(rbegin(v), rend(v), 1);
  do{
    cout << v << endl;
  } while (prev_permutation(begin(v), end(v)));

}