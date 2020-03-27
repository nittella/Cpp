#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<string,set<string>> dictionary;
  for (int i = 0; i < q; i++) {
    string operation;
    cin>>operation;
    if (operation=="ADD"){
      string word1, word2;
      cin>>word1>>word2;
      dictionary[word1].insert(word2);
      dictionary[word2].insert(word1);

    }else if (operation=="COUNT"){
      string word;
      cin>>word;
      cout<<dictionary[word].size()<<endl;

    }else if(operation=="CHECK"){
      string word1,word2;
      cin>>word1>>word2;
      bool is_synonims= false;
      for (const auto& word : dictionary[word1]){
          if (word==word2){
            is_synonims=true;
            cout<<"YES"<<endl;
            break;
          }
      }
      if(!is_synonims){
        cout<<"NO"<<endl;
      }


    }

  }
  return 0;
}