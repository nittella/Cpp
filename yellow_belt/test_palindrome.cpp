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

bool IsPalindrom(const string& s) {
  for (int i = 0; i<s.size()/2; i++){
    if (s[i]!=s[s.size()-1-i]){
      return false;
    }
  }
  return true;
}

void TestIsPalindrom(){
  //test on palindroms
  Assert(IsPalindrom("madam"), "hint_1");
  Assert(IsPalindrom("level"), "hint_2");
  Assert(IsPalindrom("wasitacaroracatisaw"), "hint_3");
  Assert(IsPalindrom("maam"), "hint_4");
  Assert(IsPalindrom("levvel"), "hint_5");
  Assert(IsPalindrom("wasitacarracatisaw"), "hint_6");
  // test empty string
  Assert(IsPalindrom(""), "hint_7");
  //test one symbol
  Assert(IsPalindrom("l"), "hint_8");
  // test space character
  Assert(IsPalindrom("a a"), "hint_9");
  Assert(IsPalindrom("a  a"), "hint_10");
  Assert(IsPalindrom(" "), "hint_11");
  //test another character
  Assert(IsPalindrom("a#$#a"), "hint_12");
  Assert(IsPalindrom("a$$a"), "hint_13");
  Assert(IsPalindrom("%"), "hint_14");
  //test first symbol, size and space
  Assert(!IsPalindrom("vasitacaroracatisaw"), "hint_15");
  Assert(!IsPalindrom("wasitacalracatisaw"), "hint_16");
  Assert(!IsPalindrom("l evel"), "hint_17");
  Assert(IsPalindrom("wasitacar racatisaw"), "hint_18");
  //test big or small size
  Assert(!IsPalindrom("aBcba"), "hint_19");
  Assert(!IsPalindrom("Abcba"), "hint_20");
  Assert(IsPalindrom("ABcBA"), "hint_21");
  Assert(!IsPalindrom("baobab"), "hint_22");
  Assert(!IsPalindrom("ab"), "hint_23");
  Assert(IsPalindrom("aa"), "hint_24");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestIsPalindrom, "TestIsPalindrom");
  return 0;
}
