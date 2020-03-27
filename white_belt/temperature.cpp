#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for (auto& c : v){
        cin>>c;
        sum+=c;
    }
    int average_temperature=sum/n;
    vector<int> day_nums;
    for (int i = 0; i <v.size();i++){
        if(v[i]>average_temperature){
            day_nums.push_back(i);
        }
    }
    cout<<day_nums.size()<<endl;
    for (auto c : day_nums){
        cout<<c<<" ";
    }


    return 0;
}
