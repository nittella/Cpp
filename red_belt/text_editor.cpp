#include <string>
#include <list>
#include "test_runner.h"
using namespace std;


class Editor {
 public:
  // Реализуйте конструктор по умолчанию и объявленные методы
  Editor(){
      cursor_ = text_.begin();
      position_ = 0;
      LogEditor("CUNSTRUCTOR");
  };
  void Left(){
      if(cursor_ != text_.begin()){
          --cursor_;
          --position_;
      }
      LogEditor("LEFT");
  };

  void Right(){
      if(cursor_ != text_.end()){
          ++cursor_;
          ++position_;
      }
      LogEditor("RIGHT");
  };
  void Insert(char token){
      text_.emplace(cursor_, token);
      ++position_;
      LogEditor("INSERT");
  };

  void Cut(size_t tokens = 1){
      clipboard_.clear();
      list<int> tmp;
      int cutted_elements = min(tokens, text_.size() - position_);
      auto new_cursor = next(cursor_, cutted_elements);
      if(cursor_ != text_.end()){
          clipboard_.splice(
                  clipboard_.begin(),
                  text_,
                  cursor_,
                  next(cursor_, cutted_elements)
          );
      }
      cursor_ = new_cursor;

      LogEditor("CUT");
  };
  void Copy(size_t tokens = 1){
      clipboard_.clear();
      clipboard_.insert(
              clipboard_.begin(),
              cursor_,
              next(cursor_, min(tokens, text_.size() - position_))
              );

      LogEditor("COPY");
  };
  void Paste(){
      text_.insert(cursor_, clipboard_.begin(), clipboard_.end());
      position_ = position_ + clipboard_.size();

      LogEditor("PASTE");
  };
  string GetText() const{
      string result;
      result.resize(text_.size());
      int count = 0;
      for(auto i : text_){
          result[count] = i;
          ++count;
      }
      LogEditor("GET_TEXT");
      return result;
  };

private:
    list<char> text_;
    list<char> clipboard_;
    list<char>::iterator cursor_;
    size_t position_;

    void LogEditor(const string operation_name) const {
//        cout << operation_name << '\n';
//        cout << "text_:" << '\n';
//        for (auto it = text_.begin(); it != text_.end(); it++){
//            if(it == cursor_){
//                cout << '|';
//            }
//            cout << *it;
//        }
//        if(cursor_ == text_.end()){
//            cout << '|';
//        }
//        cout << '/';
//        cout << '\n';
//
//        cout << "clipboard_:" << '\n';
//        for (auto it = clipboard_.begin(); it != clipboard_.end(); it++){
//            cout << *it;
//        }
//        cout << '/';
//        cout << '\n';
//        cout << "position: " << position_ << "/" << text_.size() << '\n';
//        cout << endl;

    }
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len); //|world
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", "); //word, |
    editor.Paste(); //word, hello, |
    editor.Left(); //word, hello,| /
    editor.Left(); //word, hello|, /
    editor.Cut(3);//word, hello|/
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}