#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,int> BuildCharCounters(const string& word){
    map<char,int> result;
    for (const auto& w : word ){
        result[w]++;
    }
    return result;
}

int main(){
    int q;
    cin>>q;
    for (int i=0; i<q; i++){
        string word_1, word_2;
        cin>>word_1>>word_2;
        map<char,int> map_1 = BuildCharCounters(word_1);
        map<char,int> map_2 = BuildCharCounters(word_2);
        if(map_1==map_2){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}