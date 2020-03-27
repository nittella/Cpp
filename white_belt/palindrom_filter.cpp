#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s){
    for (int i = 0; i<s.size()/2; i++){
        if (s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> palindrom_words;
    for (auto w : words){
        if (w.size()>=minLength && IsPalindrom(w)){
            palindrom_words.push_back(w);
        }
    }
    return palindrom_words;
}

int main(){
    vector<string> words={"weew","bro","code"};
    int minLength = 4;
    words = PalindromFilter(words,minLength);
    for (auto w:words){
        cout<<w<<", ";
    }

    return 0;
}