#include "tests.h"

void TestSum(){
  //test zero
    AssertEqual(Sum(0, 0), 0, "hint_1");
    AssertEqual(Sum(0, 1), 1, "hint_2");
    AssertEqual(Sum(1, 0), 1, "hint_3");

    AssertEqual(Sum(1, 2), 3, "hint_4");
    AssertEqual(Sum(-1, -2), -3, "hint_5");
    AssertEqual(Sum(-1, 2), 1, "hint_6");
    AssertEqual(Sum(1, -2), -1, "hint_7");
};

void TestReverse(){
  AssertEqual(Reverse(""), "", "hint_1");
  AssertEqual(Reverse("a"), "a", "hint_2");
  AssertEqual(Reverse("ab"), "ba", "hint_3");
  AssertEqual(Reverse("abc"), "cba", "hint_4");
  AssertEqual(Reverse("abcd"), "dcba", "hint_5");
  AssertEqual(Reverse("ab cd"), "dc ba", "hint_6");
};

void TestSort(){
  {
    vector<int> v, sorted_v;
    Sort(v);
    AssertEqual(v, sorted_v, "hint_1");
  }
  {
    vector<int> v = {5, 1, 2};
    vector<int> sorted_v = {1, 2, 5};
    Sort(v);
    AssertEqual(v, sorted_v, "hint_2");
  }
  {
    vector<int> v = {5, -1, 0};
    vector<int> sorted_v = {-1, 0, 5};
    Sort(v);
    AssertEqual(v, sorted_v, "hint_3");
  }
  {
    vector<int> v = {-2, -1, -5};
    vector<int> sorted_v = {-5, -2, -1};
    Sort(v);
    AssertEqual(v, sorted_v, "hint_4");
  }
};

void TestAll(){
  TestRunner runner;
  runner.RunTest(TestSum, "TestSum");
  runner.RunTest(TestReverse, "TestReverse");
  runner.RunTest(TestSort, "TestSort");
};