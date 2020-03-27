#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <typename T> T Sqr(const T& x);
template <typename First, typename Second> map<First, Second> Sqr(const map<First, Second>& m);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);

template <typename T>
T Sqr(const T& x){
  return x * x;
}

template <typename First, typename Second>
map<First, Second> Sqr(const map<First, Second>& m) {
  map<First, Second> result;
  for (auto i : m){
    result[i.first] = Sqr(i.second);
  }
  return result;
}
template <typename T>
vector<T> Sqr(const vector<T>& v){
  vector<T> result;
  for (int i = 0; i < v.size(); i++){
    result.push_back(Sqr(v[i]));
  }
  return result;
}
template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p){
  return make_pair(Sqr(p.first), Sqr(p.second));
}


int main(){
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
          {4, {2, 2}},
          {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }
return 0;
}