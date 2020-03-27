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
  int MAX_REQUEST_NUMBER = 1'000'000;

  PriorityCollection()
  : id_to_raiting(MAX_REQUEST_NUMBER, -1),
  raiting_to_it(MAX_REQUEST_NUMBER){
      raiting_to_ids = {{}, {}};
      for (int i = 0; i < MAX_REQUEST_NUMBER; i++){
          raiting_to_it.push_back(raiting_to_ids.begin());
      }
  }

  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object){
      Id id = id_to_object.size();
      id_to_object.push_back(move(object));
      id_to_raiting[id] = 0;

      (*next(raiting_to_ids.begin())).insert(id);
      raiting_to_it[id] = next(raiting_to_ids.begin());

      return id;
  };

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin){
      for (; range_begin != range_end; range_begin++){
          *(ids_begin++) = Add(move(*range_begin));
      }

  };

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const{
      if( id < 0 || id_to_raiting[id] == -1){
          return false;
      } else {
          return true;
      }
  };

  // Получить объект по идентификатору
  const T& Get(Id id) const{
      return id_to_object[id];
  };

  // Увеличить приоритет объекта на 1
  void Promote(Id id) {
      int old_raiting = id_to_raiting[id];
      int new_raiting = ++id_to_raiting[id];
      if((*raiting_to_it[old_raiting]).size() <= 1){
          raiting_to_ids.erase(raiting_to_it[old_raiting]);
      } else {
          (*raiting_to_it[old_raiting]).erase(id);
      }

      if(raiting_to_it[new_raiting] == raiting_to_ids.begin()){
          raiting_to_ids.insert(next(raiting_to_it[old_raiting]), {id});
      } else {
          (*raiting_to_it[new_raiting]).insert(id);
      }

  };

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const{
      int id = *prev((raiting_to_ids.back()).end());
      int priority = id_to_raiting[id];
      return {id_to_object[id], priority};
  };

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax(){
      int id = *prev((raiting_to_ids.back()).end());
      int priority = id_to_raiting[id];
      T object = move(id_to_object[id]);
      id_to_raiting[id] = -1;
      if(raiting_to_ids.back().size() <= 1){
          raiting_to_ids.pop_back();
      } else {
          raiting_to_ids.back().erase(prev(raiting_to_ids.back().end()));
      }
      raiting_to_it[priority] = raiting_to_ids.begin();
      return make_pair(move(object), priority);

  };

private:
  // Приватные поля и методы
  vector<T> id_to_object;
  vector<int> id_to_raiting;

  vector<list<set<Id>>::iterator> raiting_to_it;
  list<set<Id>> raiting_to_ids;

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

  strings.Promote(yellow_id);
  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }
  strings.Promote(yellow_id);

  // test GetMax = OK
  {
      const auto item = strings.GetMax();
      ASSERT_EQUAL(item.first, "red");
      ASSERT_EQUAL(item.second, 2);
  }

  //test Get = OK
  {
       ASSERT_EQUAL(strings.Get(white_id), "white");
  }

  //test Add(int1, int2, bint)
  {
      PriorityCollection<StringNonCopyable> strings2;
      vector<StringNonCopyable> source;
      source.reserve(3);
      for (auto s : {"white", "yellow", "red"}){
          source.push_back(s);
      }
      vector<int> ids(3);
      strings2.Add(source.begin(), source.end(), ids.begin());
      auto it = ids.begin();
      for(auto s : {"white", "yellow", "red"}){
          ASSERT_EQUAL(strings2.Get(*it), s);
          ++it;
      }
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

void TestBigData(){

};

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
