#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    for(auto c : source){
        destination.push_back(c);
    }
    source.clear();
}
int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for(auto c : destination){
        cout<<c<<" ";
    }

    return 0;
}