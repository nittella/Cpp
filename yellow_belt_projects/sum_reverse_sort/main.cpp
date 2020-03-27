#include <iostream>
#include "sum_reverse_sort.h"
#include "tests.h"
using namespace std;

int main() {
  TestAll();
  cout << Sum(5,6) << endl;
  cout << Reverse("mama") << endl;
  vector<int> v  = {3, 2, 1};
  Sort(v);
  cout << v << endl;
  return 0;
}