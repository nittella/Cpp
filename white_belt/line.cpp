#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int q;
    cin>>q;
    vector<bool> who_is_worry(0, false);
    string what_happend;
    int n;
    for (q; q>0;q--){
        cin>>what_happend;
        if (what_happend=="COME"){
            cin>>n;
            who_is_worry.resize(who_is_worry.size()+n);
        }
        if (what_happend=="QUIET"){
            cin>>n;
            who_is_worry[n]= false;
        }
        if (what_happend=="WORRY"){
            cin>>n;
            who_is_worry[n]= true;
        }
        if (what_happend=="WORRY_COUNT"){
            int num_worry_people=0;
            for (auto c : who_is_worry){
                if(c){
                    num_worry_people+=1;
                }
            }
            cout<<num_worry_people<<endl;
        }

    }


    return 0;
}