#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }

  string GetFullName(int year) {
    bool first_name_marker, last_name_marker;
    string first_name, last_name;
    tie(first_name_marker, first_name) = GetFirstName(year);
    tie(last_name_marker,last_name) = GetLastName(year);
    if (first_name_marker && last_name_marker){
      return first_name + " " + last_name;
    } else if(first_name_marker){
      return first_name + " with unknown last name";
    } else if (last_name_marker){
      return last_name + " with unknown first name";
    } else{
      return "Incognito";
    }
  }

  pair<bool, string> GetFirstName(const int& year){
    bool first_name_marker = false;
    string first_name = "";
    for (auto item : first_names){
      if (item.first > year){
        break;
      } else{
        first_name = item.second;
        first_name_marker = true;
      }
    }
    return make_pair(first_name_marker, first_name);
  }

  pair<bool, string> GetLastName(const int& year){
    bool last_name_marker = false;
    string last_name = "";
    for (auto item : last_names){
      if (item.first > year){
        break;
      } else{
        last_name = item.second;
        last_name_marker = true;
      }
    }
    return make_pair(last_name_marker, last_name);
  }

private:
    map<int, string> first_names;
    map<int, string> last_names;

};

void TestChangeFirstName(){
  {
    //test empty person
    Person empty;
    empty.ChangeFirstName(2, "Elizabeth");
    AssertEqual(empty.GetFullName(2),"Elizabeth with unknown last name", "hint_1");
    AssertEqual(empty.GetFullName(2005),"Elizabeth with unknown last name", "hint_2");
    AssertEqual(empty.GetFullName(1),"Incognito", "hint_3");
  }
  {
    //change first name in greater year
    Person person;
    person.ChangeFirstName(2, "a");
    person.ChangeFirstName(4, "c");
    person.ChangeFirstName(5, "d");
    AssertEqual(person.GetFullName(1), "Incognito", "hint_4");
    AssertEqual(person.GetFullName(2), "a with unknown last name", "hint_5");
    AssertEqual(person.GetFullName(3), "a with unknown last name", "hint_6");
    AssertEqual(person.GetFullName(4), "c with unknown last name", "hint_7");
    AssertEqual(person.GetFullName(5), "d with unknown last name", "hint_8");
    AssertEqual(person.GetFullName(6), "d with unknown last name", "hint_9");
  }
  {
    //change first name in less year
    Person person;
    person.ChangeFirstName(5, "d");
    person.ChangeFirstName(4, "c");
    person.ChangeFirstName(2, "a");
    AssertEqual(person.GetFullName(1), "Incognito", "hint_10");
    AssertEqual(person.GetFullName(2), "a with unknown last name", "hint_11");
    AssertEqual(person.GetFullName(3), "a with unknown last name", "hint_12");
    AssertEqual(person.GetFullName(4), "c with unknown last name", "hint_13");
    AssertEqual(person.GetFullName(5), "d with unknown last name", "hint_14");
    AssertEqual(person.GetFullName(6), "d with unknown last name", "hint_15");
  }
}

void TestChangeLastName(){
  {
    //test empty person
    Person empty;
    empty.ChangeLastName(2, "Elizabeth");
    AssertEqual(empty.GetFullName(2),"Elizabeth with unknown first name", "hint_16");
    AssertEqual(empty.GetFullName(2005),"Elizabeth with unknown first name", "hint_17");
    AssertEqual(empty.GetFullName(1),"Incognito", "hint_18");
  }
  {
    //change first name in greater year
    Person person;
    person.ChangeLastName(2, "a");
    person.ChangeLastName(4, "c");
    person.ChangeLastName(5, "d");
    AssertEqual(person.GetFullName(1), "Incognito", "hint_19");
    AssertEqual(person.GetFullName(2), "a with unknown first name", "hint_20");
    AssertEqual(person.GetFullName(3), "a with unknown first name", "hint_21");
    AssertEqual(person.GetFullName(4), "c with unknown first name", "hint_22");
    AssertEqual(person.GetFullName(5), "d with unknown first name", "hint_23");
    AssertEqual(person.GetFullName(6), "d with unknown first name", "hint_24");
  }
  {
    //change first name in less year
    Person person;
    person.ChangeLastName(5, "d");
    person.ChangeLastName(4, "c");
    person.ChangeLastName(2, "a");
    AssertEqual(person.GetFullName(1), "Incognito", "hint_25");
    AssertEqual(person.GetFullName(2), "a with unknown first name", "hint_26");
    AssertEqual(person.GetFullName(3), "a with unknown first name", "hint_27");
    AssertEqual(person.GetFullName(4), "c with unknown first name", "hint_28");
    AssertEqual(person.GetFullName(5), "d with unknown first name", "hint_29");
    AssertEqual(person.GetFullName(6), "d with unknown first name", "hint_30");
  }
}

void TestGetFullName(){
  {
    //test empty
    Person empty;
    AssertEqual(empty.GetFullName(1),"Incognito", "hint_31");
    //using GetFullName doesn't change person
    AssertEqual(empty.GetFullName(1),"Incognito", "hint_32");
  }
  {
    Person person;
    person.ChangeFirstName(1, "a");
    person.ChangeLastName(1, "aa");
    AssertEqual(person.GetFullName(1), "a aa", "hint_33");
  }
  {
    Person person;
    person.ChangeFirstName(1, "a");
    person.ChangeLastName(2, "aa");
    AssertEqual(person.GetFullName(1), "a with unknown last name", "hint_34");
    AssertEqual(person.GetFullName(2), "a aa", "hint_35");
    AssertEqual(person.GetFullName(3), "a aa", "hint_36");
  }

  {
    Person person;
    person.ChangeFirstName(2, "a");
    person.ChangeLastName(1, "aa");
    AssertEqual(person.GetFullName(1), "aa with unknown first name", "hint_37");
    AssertEqual(person.GetFullName(2), "a aa", "hint_38");
    AssertEqual(person.GetFullName(3), "a aa", "hint_39");
  }
  {
    Person person;
    person.ChangeFirstName(1, "a");
    person.ChangeLastName(2, "aa");
    person.ChangeFirstName(3, "b");
    person.ChangeLastName(4, "bb");
    person.ChangeFirstName(5, "c");
    AssertEqual(person.GetFullName(1), "a with unknown last name", "hint_40");
    AssertEqual(person.GetFullName(2), "a aa", "hint_41");
    AssertEqual(person.GetFullName(3), "b aa", "hint_42");
    AssertEqual(person.GetFullName(4), "b bb", "hint_43");
    AssertEqual(person.GetFullName(5), "c bb", "hint_44");
    AssertEqual(person.GetFullName(6), "c bb", "hint_45");
    AssertEqual(person.GetFullName(1), "a with unknown last name", "hint_46");
    AssertEqual(person.GetFullName(2), "a aa", "hint_47");
    AssertEqual(person.GetFullName(3), "b aa", "hint_48");
    AssertEqual(person.GetFullName(4), "b bb", "hint_49");
    AssertEqual(person.GetFullName(5), "c bb", "hint_50");
    AssertEqual(person.GetFullName(6), "c bb", "hint_51");
  }
  {
    Person person;
    person.ChangeFirstName(5, "c");
    person.ChangeLastName(4, "bb");
    person.ChangeFirstName(3, "b");
    person.ChangeLastName(2, "aa");
    person.ChangeFirstName(1, "a");
    AssertEqual(person.GetFullName(1), "a with unknown last name", "hint_52");
    AssertEqual(person.GetFullName(2), "a aa", "hint_53");
    AssertEqual(person.GetFullName(3), "b aa", "hint_54");
    AssertEqual(person.GetFullName(4), "b bb", "hint_55");
    AssertEqual(person.GetFullName(5), "c bb", "hint_56");
    AssertEqual(person.GetFullName(6), "c bb", "hint_57");
    AssertEqual(person.GetFullName(1), "a with unknown last name", "hint_58");
    AssertEqual(person.GetFullName(2), "a aa", "hint_59");
    AssertEqual(person.GetFullName(3), "b aa", "hint_60");
    AssertEqual(person.GetFullName(4), "b bb", "hint_61");
    AssertEqual(person.GetFullName(5), "c bb", "hint_62");
    AssertEqual(person.GetFullName(6), "c bb", "hint_63");
  }
}


int main() {
  TestRunner runner;
  runner.RunTest(TestChangeFirstName, "TestChangeFirstName");
  runner.RunTest(TestChangeLastName, "TestChangeLastName");
  runner.RunTest(TestGetFullName, "GetFullName");
  return 0;
}
