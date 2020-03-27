#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

#include "profile.h"
#include "test_runner.h"

using namespace std;

//class Learner {
//private:
//    vector<string> dict;
//
//public:
//    int Learn(const vector<string>& words) {
//        int newWords = 0;
//        for (const auto& word : words) {
//            if (find(dict.begin(), dict.end(), word) == dict.end()) {
//                ++newWords;
//                dict.push_back(word);
//            }
//        }
//        return newWords;
//    }
//
//    vector<string> KnownWords() {
//        sort(dict.begin(), dict.end());
//        dict.erase(unique(dict.begin(), dict.end()), dict.end());
//        return dict;
//    }
//};

class Learner {
 private:
  set<string> dict;
 public:
    int Learn(const vector<string>& words) {
        int newWords = 0;
        for (const auto& word : words) {
            if (dict.find(word) == dict.end()) {
                dict.insert(word);
                ++newWords;
            }
        }
        return newWords;
    }

  vector<string> KnownWords() {
        vector<string> result;
        for (const auto& word : dict){
            result.push_back(word);
        }
        return result;
  }
};

void TestTime(){
    Learner learner;
    ifstream input_1("dictionary.txt");
    vector<string> new_words;
    for (int i = 0; i < 5000; i++){
        string word = to_string(i);
        new_words.push_back(word);
    }
    {
        LOG_DURATION("Learn in empty dict");
        learner.Learn(new_words);
    }
    for (int i = 2500; i < 7500; i++){
        string word = to_string(i);
        new_words.push_back(word);
    }
    {
        LOG_DURATION("Learn in filled dict");
        learner.Learn(new_words);
    }
    {
        LOG_DURATION("Lots of Learn");
        for (auto i = 0; i < 1000; i++){
            learner.Learn({"1", "2", "a", "b"});
        }
    }
    {
        LOG_DURATION("Known words");
        learner.KnownWords();
    }



}

void  TestUnique(){
    Learner learner;
    ASSERT_EQUAL(learner.Learn({"hello"}), 1);
    ASSERT_EQUAL(learner.Learn({"hello", "world"}), 1);
    ASSERT_EQUAL(learner.Learn({"good", "bye", "world", "good", "bye"}), 2);
    vector<string> tmp = {"bye", "good", "hello", "world"};
    ASSERT_EQUAL(learner.KnownWords(), tmp);
}

int main(){
    TestRunner tr;
    RUN_TEST(tr, TestTime);
    RUN_TEST(tr, TestUnique);

    return 0;
}