#pragma once

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename K, typename V>
ostream& operator<< (ostream& os, const map<K, V>& m);

template <typename T>
ostream& operator<< (ostream& os, const set<T>& s);

template <typename T>
ostream& operator<< (ostream& os, const vector<T> v);

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    ~TestRunner();
private:
    int fail_count = 0;
};


template <typename K, typename V>
ostream& operator<< (ostream& os, const map<K, V>& m){
  os << "{";
  bool first = true;
  for (const auto& item : m){
    if(!first){
      os << ", ";
    }
    first = false;
    os << item.first << ": " << item.second;
  }
  return os << "}";
}

template <typename T>
ostream& operator<< (ostream& os, const set<T>& s){
  os << "{";
  bool first = true;
  for (const auto& item : s){
    if(!first){
      os << ", ";
    }
    first = false;
    os << item;
  }
  return os << "}";

}

template <typename T>
ostream& operator<< (ostream& os, const vector<T> v){
  os << "[";
  bool first = true;
  for (const auto& item : v){
    if(!first){
      os << ", ";
    }
    first = false;
    os << item;
  }
  return os << "]";
};

//test framework
template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint){
  if( t != u){
    stringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " Hint: " << hint;
    throw runtime_error(os.str());
  }
}

template <typename TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name){
  try {
    func();
    cerr << test_name << " OK" << endl;
  } catch (runtime_error& e){
    ++fail_count;
    cerr << test_name << " fail: " << e.what() << endl;
  }
}