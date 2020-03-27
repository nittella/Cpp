#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
  typename set<T>::iterator border_it = find_if(
          begin(elements), end(elements),
          [border](T element){ return element > border;}
          );
  vector<T> result;
  auto it = border_it;
  while (it != end(elements)){
    result.push_back(*it);
    it++;
  }
  return result;
};

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
