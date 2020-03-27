#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  ifstream input("input.txt");

  double n;
  cout << fixed << setprecision(3);
  while (input >> n) {

    cout << n << endl;
  }

  return 0;
}