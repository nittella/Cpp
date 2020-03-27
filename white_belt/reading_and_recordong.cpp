#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string ReadAll(const string& path_in){
  ifstream input(path_in);
  string line = "";
  string result;
  while (getline(input, line)){
    result +=line;
    result +='\n';
  }
  return result;
}

void RecordAll(const string& lines, const string& path_out){
  ofstream output(path_out);
  output << lines;
}

int main() {
  string path_in = "input.txt";
  string path_out = "output.txt";
  RecordAll(ReadAll(path_in), path_out);
  return 0;
}