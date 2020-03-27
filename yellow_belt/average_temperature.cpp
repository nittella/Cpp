#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main(){
//  cout << numeric_limits<int>::max();
  int n;
  cin >> n;
  vector<int> temperatures;
  int64_t sum = 0;
  for (int k = 0; k < n; k++){
    int tmp;
    cin >> tmp;
    temperatures.push_back(tmp);
    sum += tmp;
  }
  int64_t avg = sum / n;
  vector<int> avg_temp_nums;
  for (int  k = 0; k < n; k++){
    if(temperatures.at(k)> avg){
      avg_temp_nums.push_back(k);
    }
  }
  cout << avg_temp_nums.size() << endl;
  for (int  k = 0; k < avg_temp_nums.size(); k++){
    cout << avg_temp_nums.at(k);
    if (k < avg_temp_nums.size() - 1){
      cout << " ";
    }
  }

  return 0;
}