#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class PriorityCollection {
public:
  using Id = int;
  using Raiting = int;
  using Priority = pair<Raiting, Id>;


  PriorityCollection():
  validity(1'000'000, false),
  iterators(1'000'000),
  priorities(1'000'000){};


  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object){
      Priority priority  = make_pair(0, current_id);
      objects.push_back(move(object));
      priorities[current_id] = priority;
      iterators[current_id] = prev(objects.end());
      priority_to_counter.insert(make_pair(priority, current_id));
      validity[current_id] = true;
      ++current_id;
      return current_id - 1;
  };

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin){
      for (;range_begin != range_end; range_begin++){
          *ids_begin = Add(*make_move_iterator(range_begin));
          ++ids_begin;
      }
  };

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const{
      return validity[id];

  };

  // Получить объект по идентификатору
  const T& Get(Id id) const{
      return *iterators[id];
  };

  // Увеличить приоритет объекта на 1
  void Promote(Id id){
      priority_to_counter.erase(make_pair(priorities[id], id));
      ++priorities[id].first;
      priority_to_counter.insert(make_pair(priorities[id], id));
  };

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const{
      Priority max_priority = (*prev(priority_to_counter.end())).first;
      Id id = (*prev(priority_to_counter.end())).second;
      return {*iterators[id], max_priority.first};
  };

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax(){
      Priority priority = (*prev(priority_to_counter.end())).first;
      Id id = (*prev(priority_to_counter.end())).second;
      T object = move(*iterators[id]);
      Raiting raiting = priority.first;
      objects.erase(iterators[id]);
      priority_to_counter.erase(make_pair(priority, priority.second));
      validity[id] = false;
      return {move(object), raiting};

  };

private:
  // Приватные поля и методы
  Id current_id= 0;
  list<T> objects;
  set<pair<Priority, Id>> priority_to_counter;

  vector<typename list<T>::iterator> iterators;
  vector<Priority> priorities;
  vector<bool> validity;



};

class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
  StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");
  const auto yellow_id = strings.Add("yellow");
  const auto red_id = strings.Add("red");

  ASSERT_EQUAL(strings.Get(red_id), "red");
  ASSERT(strings.IsValid(red_id));

  strings.Promote(yellow_id);
  for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
  strings.Promote(yellow_id);


  {
        const auto item = strings.GetMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }

    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "yellow");
    ASSERT_EQUAL(item.second, 2);
  }
  {
      const auto item = strings.PopMax();
      ASSERT_EQUAL(item.first, "white");
      ASSERT_EQUAL(item.second, 0);
  }


}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
