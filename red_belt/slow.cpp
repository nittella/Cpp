#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>

#include "test_runner.h"
#include "profile.h"

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : user_page_counts_(MAX_USER_COUNT_ + 1, 0),
        sorted_users_(),
        user_positions_(MAX_USER_COUNT_ + 1, -1) {}

  void Read(int user_id, int page_count) {
    if (user_page_counts_[user_id] == 0) {
      AddUser(user_id);
    }
    user_page_counts_[user_id] = page_count;
    int& position = user_positions_[user_id];
    while (position > 0 && page_count > user_page_counts_[sorted_users_[position - 1]]) {
      SwapUsers(position, position - 1);
    }
  }

  double Cheer(int user_id) const {
    if (user_page_counts_[user_id] == 0) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = user_page_counts_[user_id];
    int position = user_positions_[user_id];
    while (position < user_count &&
      user_page_counts_[sorted_users_[position]] == page_count) {
      ++position;
    }
    if (position == user_count) {
        return 0;
    }
    // По умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // Простой способ сделать это — умножить его на 1.0.
    return (user_count - position) * 1.0 / (user_count - 1);
  }

private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;

  vector<int> user_page_counts_;
  vector<int> sorted_users_;   // отсортированы по убыванию количества страниц
  vector<int> user_positions_; // позиции в векторе sorted_users_

  int GetUserCount() const {
    return sorted_users_.size();
  }
  void AddUser(int user_id) {
    sorted_users_.push_back(user_id);
    user_positions_[user_id] = sorted_users_.size() - 1;
  }
  void SwapUsers(int lhs_position, int rhs_position) {
    const int lhs_id = sorted_users_[lhs_position];
    const int rhs_id = sorted_users_[rhs_position];
    swap(sorted_users_[lhs_position], sorted_users_[rhs_position]);
    swap(user_positions_[lhs_id], user_positions_[rhs_id]);
  }
};

struct Request{
    string type;
    int user_id;
    int page = 0;
};

void TestCorrectness(){
    {
        ReadingManager manager;
        int u = 1;
        int max_users = 100'000;
        int max_pages = 1'000;
        while(u <= max_users){
            for (int i = 1; i <= max_pages; i++){
                manager.Read(u, i);
                u++;
            }
        }
        u = 1;
        double n = max_users * 1.0 / max_pages;
        while(u <= max_users){
            for (int i = 1; i <= max_pages; i++){
                ASSERT_EQUAL(manager.Cheer(u), (i - 1) * 1.0 * n / (max_users - 1));
                u++;
            }
        }
        max_users = 100;
        max_pages = 1000;
        u = 1;
        while(u <= max_users){
            for (int i = 1; i <= max_pages; i++){
                manager.Read(u, i);
                u++;
            }
        }
        u = 1;
        while(u <= max_users){
            for (int i = 1; i <= max_pages; i++){
                ASSERT_EQUAL(manager.Cheer(u), (i - 1) * 1.0 * n / (max_users - 1));
                u++;
            }
        }

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TestRunner tr;
    RUN_TEST(tr, TestCorrectness);
    return 0;
}