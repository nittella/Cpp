#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
      T* result;
      if(!realesed_objects_.empty()){
          result = realesed_objects_.front();
          selected_objects_.insert(realesed_objects_.front());
          realesed_objects_.pop_front();
      } else {
          T*  tmp = new T;
          result = tmp;
          selected_objects_.insert(result);
      }
      return result;
  };
  T* TryAllocate(){
      T* result;
      if(!realesed_objects_.empty()){
          result = realesed_objects_.front();
          selected_objects_.insert(realesed_objects_.front());
          realesed_objects_.pop_front();
          return result;
      } else {
          return nullptr;
      }

  };

  void Deallocate(T* object){
      if (selected_objects_.find(object) == selected_objects_.end()){
          throw invalid_argument("");
      } else {
          realesed_objects_.push_back(object);
          selected_objects_.erase(object);
      }
  };

  ~ObjectPool(){
      for (auto object : realesed_objects_){
          delete object;
      }
      for (auto object : selected_objects_){
          delete object;
      }
  };

private:
  deque<T*> realesed_objects_;
  set<T*> selected_objects_;

};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
