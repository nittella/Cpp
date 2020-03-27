#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
    int n=0;
    vector<vector<string>> deals(days[n]);
    int q;
    cin>>q;
    for (q;q>0;q--){
        string operation;
        cin>>operation;
        if (operation=="ADD"){
            int i;
            cin>>i;
            string s;
            cin>>s;
            deals[i-1].push_back(s);
        }
        if (operation=="NEXT"){
            vector<vector<string>> old_deals=deals;
            int days_in_old_month = days[n];
            if (n!=11){
                n++;
            }
            else{
                n=0;
            }
            int days_in_new_month = days[n];
            deals.resize(days[n]);
            if(days_in_old_month>days_in_new_month){
                vector<string> tmp;
                for (int i=days_in_new_month-1; i<days_in_old_month; i++){
                    tmp.insert(end(tmp),begin(old_deals[i]),end(old_deals[i]));
                    deals[deals.size()-1]=tmp;
                }
            }
        }
        if (operation=="DUMP"){
            int i;
            cin>>i;
            cout<<deals[i-1].size()<<" ";
            if (deals[i-1].size()!=0){
                for (auto c : deals[i-1]){
                    cout<<c<<" ";
                }
            }
            cout<<endl;

        }
    }

    return 0;
}