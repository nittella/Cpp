#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

vector<string> SplitIntoWords(const string& s){
 int q = count(begin(s), end(s), ' ');
 vector<string> result;
 auto begin_it = begin(s);
 for (int i = 0; i <= q; i++){
   auto it = find(begin_it, end(s), ' ');
   result.push_back(string(begin_it, it));
   begin_it = ++it;
 }
  return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
