#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border){
  if (numbers.empty()){
    return end(numbers);
  }
  auto range = equal_range(begin(numbers), end(numbers), border);

  if(range.first == range.second){
    if (range.second == end(numbers)){
      return prev(end(numbers));
    } else{
      if (range.first == begin(numbers)){
        return range.first;
      }
      if(border - *prev(range.first) > *range.second - border){
        return range.second;
      } else{
        return prev(range.first);
      }
    }
  } else {
    if(range.second == end(numbers)){
      return range.first;
    } else {
       if (border - *range.first > *range.second - border){
         return  range.second;
       } else {
         return range.first;
       }
    }
  }
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
       *FindNearestElement(numbers, 0) << " " <<
       *FindNearestElement(numbers, 3) << " " <<
       *FindNearestElement(numbers, 5) << " " <<
       *FindNearestElement(numbers, 6) << " " <<
       *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
