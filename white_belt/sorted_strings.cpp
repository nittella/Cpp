#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
      set_string.push_back(s);
      SortSet();
    }
    vector<string> GetSortedStrings() {
      return set_string;
    }
private:
    vector<string> set_string;
    void SortSet(){
      sort(begin(set_string),end(set_string));
    }
};


int main() {


  return 0;
}
