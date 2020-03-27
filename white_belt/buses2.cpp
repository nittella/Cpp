#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<int,vector<string>> buses;
  for (int i = 0; i < q; i++) {
    int count_stops;
    cin>>count_stops;
    vector<string> tmp;
    for (int j=0; j<count_stops;j++){
      string stop;
      cin>>stop;
      tmp.push_back(stop);
    }
    bool bus_existance = false;
    for (const auto& bus : buses){
      if (bus.second==tmp){
        cout<<"Already exists for "<<bus.first<<endl;
        bus_existance = true;
        break;
      }
    }
    if(!bus_existance){
      int buses_size=buses.size();
      buses[buses_size+1]=tmp;
      cout<<"New bus "<<buses_size+1<<endl;
    }
  }
  return 0;
}