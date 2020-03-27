#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void PrintVector(const vector<string>& v) {
  for (const auto& i : v){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main(){
  int q;
  cin>>q;
  map<string,vector<string>> buses;
  map<string,vector<string>> stops;
  for (int i=0; i<q; i++){
    string operation;
    cin>>operation;

    if (operation=="NEW_BUS"){
      string bus;
      int stop_count;
      cin>>bus>>stop_count;
      for (int j=0; j<stop_count; j++){
        string stop;
        cin>>stop;
        buses[bus].push_back(stop);
        stops[stop].push_back(bus);
      }

    }else if (operation=="BUSES_FOR_STOP"){
      string stop;
      cin>>stop;
      if (stops.count(stop)==0){
        cout<<"No stop"<<endl;
      } else {
        PrintVector(stops[stop]);
      }

    } else if (operation=="STOPS_FOR_BUS"){
      string bus;
      cin>>bus;
      if (buses.count(bus)==0){
        cout<<"No bus"<<endl;
      } else{
        for (const auto& stop : buses[bus]){
          cout<<"Stop "<<stop<<": ";
          if (stops[stop].size()==1){
            cout<<"no interchange";
          }else{
            for (const auto& i : stops[stop]){
              if (i!=bus){
                cout<<i<<" ";
              }
            }
          }
          cout<<endl;
        }
      }


    } else if (operation=="ALL_BUSES"){
      if (buses.size()==0){
        cout<<"No buses"<<endl;
      } else{
        for (const auto& item : buses){
          cout<<"Bus "<<item.first<<": ";
          PrintVector(item.second);
        }
      }

    }

  }
  return 0;
}
