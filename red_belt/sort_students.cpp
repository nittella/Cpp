#include "student.h"
#include "test_runner.h"
#include "profile.h"

#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
bool Compare(const Student& first, const Student& second) {
  return first.Less(second);
}

void TestComparison() {
  Student newbie {
    "Ivan", "Ivanov", {
      {"c++", 1.0},
      {"algorithms", 3.0}
    },
    2.0
  };

  Student cpp_expert {
    "Petr", "Petrov", {
      {"c++", 9.5},
      {"algorithms", 6.0}
    },
    7.75
  };

  Student guru {
    "Sidor", "Sidorov", {
      {"c++", 10.0},
      {"algorithms", 10.0}
    },
    10.0
  };
  ASSERT(Compare(guru, newbie));
  ASSERT(Compare(guru, cpp_expert));
  ASSERT(!Compare(newbie, cpp_expert));
}

void TestSorting() {
  vector<Student> students {
    {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
    {"Semen", "Semenov", {{"maths", 4.}}, 4.},
    {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
    {"Petr", "Petrov", {{"maths", 3.}}, 3.},
    {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
  };
  sort(students.begin(), students.end(), Compare);
  ASSERT(is_sorted(students.begin(), students.end(),
    [](Student first, Student second) {
      return first.Less(second);
    })
  );
}

void TestTime(){
        vector<Student> students;
    for (int i = 0; i< 28000; i++ ){
        string name = "Sidor" + to_string(i);
        string surname = "Sidorov" + to_string(i);
        students.push_back({
            name,
            surname,
            {{"maths",  static_cast<double>(i)}},
            static_cast<double>(i)
        });
    }
    {
        LOG_DURATION("Sort");
        sort(students.begin(), students.end(), Compare);
    }
};

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestComparison);
  RUN_TEST(tr, TestSorting);
  RUN_TEST(tr, TestTime);
  return 0;
}