#include<iostream>
#include<string>
using namespace std;

struct Specialization{
    string value;
    explicit Specialization(string new_value){
      value = new_value;
    }
};
struct Course{
    string value;
    explicit Course(string new_value){
      value = new_value;
    }
};
struct Week{
    string value;
    explicit Week(string new_value){
      value = new_value;
    }
};
struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle (Specialization new_specialization, Course new_course, Week new_week){
      specialization = new_specialization;
      course = new_course;
      week = new_week;
    }
};


int main() {

  return 0;
}
