#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<set<string>,int> buses;
  for (int i = 0; i < q; i++) {
    int count_stops;
    cin>>count_stops;
    set<string> tmp;
    for (int j=0; j<count_stops;j++){
      string stop;
      cin>>stop;
      tmp.insert(stop);
    }
    if (buses.count(tmp)==0){
      int buses_size=buses.size();
      buses[tmp]=buses_size+1;
      cout<<"New bus "<<buses_size+1<<endl;
    }else {
      cout<<"Already exists for "<<buses[tmp]<<endl;
    }
  }
  return 0;
}