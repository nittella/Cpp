#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define CONCAT(a,b) a##b
#define MACRO_1(a, b) CONCAT(a, b)
#define UNIQ_ID MACRO_1(param_, __LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}