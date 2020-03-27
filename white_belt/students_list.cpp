#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    string surname;
    int birth_day;
    int birth_month;
    int birth_year;
};

int main(){
  int n;
  cin >> n;
  vector<Student> students;
  for (int i = 0; i < n; i++){
    Student student;
    cin >> student.name >> student.surname >> student.birth_day >> student.birth_month >> student.birth_year; //is it working??
    students.push_back(student);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    string operation;
    int k;
    cin >> operation >> k;
    k--;
    if (k < students.size() && k >= 0){
      if (operation == "name"){
        cout <<students[k].name << ' ' << students[k].surname << endl;
      } else if(operation == "date"){
        cout << students[k].birth_day << '.' << students[k].birth_month << '.' << students[k].birth_year << endl;
      }
      else{
        cout << "bad request" << endl;
      }
    }
    else{
      cout << "bad request" << endl;
    }
  }

  return 0;
}