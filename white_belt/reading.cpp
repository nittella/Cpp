#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void ReadAll(const string& path){
  ifstream input(path);
  string line;
  while (getline(input, line)){
    cout << line << endl;
  }
}

int main() {
  string path = "input.txt";
  ReadAll(path);
  return 0;
}