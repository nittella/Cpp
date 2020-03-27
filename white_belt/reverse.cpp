#include <iostream>
#include <vector>
#include <string>

using namespace std;
void Reverse(vector<int>& v){
        for (int i = 0; i<v.size()/2; i++){
            int tmp = v[i];
        v[i]=v[v.size()-1-i];
        v[v.size()-1-i]=tmp;
    }
}
vector<int> Reversed(const vector<int>& v) {
    vector<int> w=v;
    Reverse(w);
    return w;
}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> w = Reversed(numbers);
    for (auto n : w){
        cout<<n<<" ";
    }

    return 0;
}