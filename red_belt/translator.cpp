#include "test_runner.h"
#include <string>
#include <deque>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target){
      string* pos_source = &(dict_.emplace_back(source));
      string* pos_target = &((dict_.emplace_back(target)));
      if(forward_dict_.){
          forward_dict_.insert(
                  {string_view(pos_source, source.size()), string_view(pos_target, target.size())}
          );
      } else {
          forward_dict_[string_view(pos_source, source.size())] =  string_view(pos_target, target.size());
      }
      if(backward_dict_.find(target) == backward_dict_.end()){
          backward_dict_.insert(
                  {string_view(pos_target, target.size()), string_view(pos_source, source.size())}
          );
      } else {
          backward_dict_[string_view(pos_target, target.size())] =  string_view(pos_source, source.size());
      }
  };

  string_view TranslateForward(string_view source) const{
      if(forward_dict_.find(source) != forward_dict_.end()){
          return forward_dict_.at(source);
      } else {
          return "";
      }
  };
  string_view TranslateBackward(string_view target) const {
      if(backward_dict_.find(target) != backward_dict_.end()){
          return backward_dict_.at(target);
      } else {
          return "";
      }
  };

private:
    map<string*, string*> forward_dict_;
    map<string*, string*> backward_dict_;
    deque<string> dict_;


};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
