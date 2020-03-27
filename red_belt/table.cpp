#include "test_runner.h"

using namespace std;

template <typename T>
class Table{
public:
    Table(const size_t& first_size, const size_t& second_size){
        vector<T> tmp(second_size);
        table = vector<vector<T>>(first_size, tmp);
    }

    void Resize(const size_t& first_size, const size_t& second_size){
        table.resize(first_size);
        for (vector<T>& v : table){
            v.resize(second_size);
        }
    }

    pair<size_t, size_t> Size() const {
        return make_pair(table.size(), (table.empty() ? 0 : table[0].size()));
    }

    vector<T>& operator[](size_t index) {
        return table[index];
    }

    const vector<T>& operator[](size_t index) const {
        return table[index];
    }

private:
    vector<vector<T>> table;
};



void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);

  return 0;
}
