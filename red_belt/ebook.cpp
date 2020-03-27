#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "profile.h"
#include "test_runner.h"

using namespace std;

class ReadingManager {
public:
    ReadingManager()
    : users_to_pages_(MAX_USER_COUNT_ + 1, 0),
    read_pages_(MAX_PAGES_COUNT_ + 2, 0){}

  void Read(int user_id, int page_count) {
        int old_page = users_to_pages_[user_id];
        users_to_pages_[user_id] = page_count;
        if (page_count != 0){
            if (old_page != 0){
                for(int i = (old_page + 1); i <= page_count; i++){
                    --read_pages_[i];
                }
            } else {
                for(int i = (page_count + 1); i <= MAX_PAGES_COUNT_ + 1; i++){
                    ++read_pages_[i];
                }
            }
        }
  }

  double Cheer(int user_id) const {

        if(users_to_pages_[user_id] == 0){
            return 0;
        }
        if(read_pages_[MAX_PAGES_COUNT_ + 1] == 1){
            return 1;
        }
        double result = (read_pages_[users_to_pages_[user_id]] * 1.0)/(read_pages_[MAX_PAGES_COUNT_ + 1] - 1);
        return result;
  }

    static const int MAX_USER_COUNT_ = 100'000;
    static const int MAX_PAGES_COUNT_ = 1'000;

private:
    vector<int> users_to_pages_;
    vector<int> read_pages_;

};

struct Request{
    string type;
    int user_id;
    int page = 0;
};

void TestCorrectness(){
    {
        ReadingManager manager;
        vector<Request> requests = {{"CHEER", 5}, {"READ", 1, 10}, {"CHEER", 1}, {"READ", 2, 5},
                                    {"READ", 3, 7}, {"CHEER", 2}, {"CHEER", 3}, {"READ", 3, 10}, {"CHEER", 3},
                                    {"READ", 3, 11}, {"CHEER", 3}, {"CHEER", 1}, {"READ", 100000, 1000}, {"CHEER", 100000},
                                    {"READ", 99999, 1000}, {"CHEER", 99999}};
        vector<double> answers = {0, 1, 0, 0.5, 0.5, 1, 0.5, 1, 0.75};
        int answ_count = 0;
        for (auto& request : requests) {
            if (request.type == "READ") {
                manager.Read(request.user_id, request.page);
            } else if (request.type == "CHEER") {
                ASSERT_EQUAL(manager.Cheer(request.user_id), answers[answ_count]);
                ++answ_count;
            }
        }

    }

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
//        max_users = 1000;
//        max_pages = 1000;
//        u = 1;
//        while(u <= max_users){
//            for (int i = 1; i <= max_pages; i++){
//                manager.Read(u, i);
//                u++;
//            }
//        }
//        u = 1;
//        while(u <= max_users){
//            for (int i = 1; i <= max_pages; i++){
//                ASSERT_EQUAL(manager.Cheer(u), (i - 1) * 1.0 * n / (max_users - 1));
//                u++;
//            }
//        }

    }
}


void TestTimeRead(){
    // 100 000 users have read 10 pages (max count of users)
    {
        ReadingManager manager;
        {
            LOG_DURATION("READ, 100 000 users have read 10 pages (max count of users)");
            for (int u = 1; u <= ReadingManager::MAX_USER_COUNT_; u++){
                for (int p = 1; p <= 10; p++){
                    manager.Read(u, p);
                }
            }
        }
    }

    // 1 000 users have read 1 000 pages (max count of pages)
    {
        ReadingManager manager;
        {
            LOG_DURATION("READ, 1 000 users have read 1 000 pages (max count of pages)");
            for (int u = 1; u <= 1000; u++){
                for (int p = 1; p <= 1000; p++){
                    manager.Read(u, p);
                }
            }
            for (int u = 1; u <= 1000; u++){
                manager.Cheer(u);
            }
        }
    }
}

void TestTimeCheer(){
    {
        ReadingManager manager;
        for (int u = 1; u <= ReadingManager::MAX_USER_COUNT_; u++){
            for (int p = 1; p <= 10; p++){
                manager.Read(u, p);
            }
        }
        {
            LOG_DURATION("CHEER, 100 000 users have read 10 pages (max count of users)");
            for (int u = 1; u <= ReadingManager::MAX_USER_COUNT_; u++){
                manager.Cheer(u);
            }
        }
    }

    // 1 000 users have read 1 000 pages (max count of pages)
    {
        ReadingManager manager;
        for (int u = 1; u <= 1000; u++){
            for (int p = 1; p <= 1000; p++){
                manager.Read(u, p);
            }
        }
        {
            LOG_DURATION("CHEER, 1 000 users have read 1 000 pages (max count of pages)");
            for (int u = 1; u <= 1000; u++){
                manager.Cheer(u);
            }
        }
    }
}




int main2() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  TestRunner tr;
  RUN_TEST(tr, TestCorrectness);
//  RUN_TEST(tr, TestTimeRead);
//  RUN_TEST(tr, TestTimeCheer);

  return 0;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}