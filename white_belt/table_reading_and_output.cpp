#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
  ifstream input("input.txt");
  int N, M;
  input >> N; // lines
  input.ignore(1);
  input >> M; // columns
  cout << right;
  for (int n = 0; n < N; n++){
    for (int m = 0; m < M; m++){
      input.ignore(1);
      int number;
      input >> number;
      cout << setw(10) << number;
      if (m < M-1){
        cout << ' ';
      }
    }
    if (n < N - 1){
      cout << endl;
    }

  }
  return 0;
}
