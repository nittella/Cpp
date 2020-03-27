#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
  if (range_end - range_begin >= 2){
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    int thrid = elements.size() / 3;
    MergeSort(begin(elements),begin(elements) + thrid);
    MergeSort(begin(elements) + thrid, begin(elements) + 2 * thrid);
    MergeSort(begin(elements) + 2 * thrid, end(elements));
    vector<typename RandomIt::value_type> tmp;
    merge(begin(elements),begin(elements) + thrid, begin(elements) + thrid, begin(elements) + 2 * thrid,
            back_inserter(tmp));
    merge(begin(tmp),end(tmp), begin(elements) + 2 * thrid, end(elements),
          range_begin);
  }
};

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}

