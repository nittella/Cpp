#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>


using namespace std;

int main() {
  int q;
  cin >> q;
  set<string> words;
  for (int i= 0; i<q;i++){
    string word;
    cin>>word;
    words.insert(word);
  }
  cout<<words.size();
  return 0;
}