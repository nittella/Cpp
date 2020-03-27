#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "profile.h"
#include "test_runner.h"

using namespace std;

class RouteManager {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].insert(finish); // log^2(Q)
    reachable_lists_[finish].insert(start); //log^2(Q)
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    auto it = reachable_lists_.find(start);
    if (it == reachable_lists_.end()) { //logQ + Q = Q -> logQ
        return result;
    }
    const set<int>& reachable_stations = it->second; //logQ

    if (!reachable_stations.empty()) {
        auto pair_it = reachable_stations.equal_range(finish);
        if(pair_it.first == reachable_stations.end() || *pair_it.first != finish){
            --pair_it.first;
        }
        auto nearest_finish = *pair_it.first;
        if (pair_it.second != reachable_stations.end()){
            nearest_finish = min(*pair_it.first, *pair_it.second,
                    [finish](int lhs, int rhs) { return abs(lhs - finish) < abs(rhs - finish);}
                    );
        }
        result = min(result, abs(nearest_finish - finish));
    }
    return result;
  }
private:
  map<int, set<int>> reachable_lists_;
};

struct Request{
    string type;
    int start, finish;
};

void TestCorrectness(){
    RouteManager routes;
    vector<Request> requests {
        {"ADD", -2, 5},
        {"ADD", 10, 4},
        {"ADD", 5, 8},
        {"GO", 4, 10},
        {"GO", 4, -2},
        {"GO", 5, 0},
        {"GO", 5, 100}
    };
    vector<int> answers {0, 6, 2, 92};

    int answ_count = 0;
    for (auto& request : requests) {

        if (request.type == "ADD") {
            routes.AddRoute(request.start, request.finish);
        } else if (request.type == "GO") {
            ASSERT_EQUAL(routes.FindNearestFinish(request.start, request.finish), answers[answ_count]);
            ++answ_count;
            }
    }

}

void TestTimeGo(){
    {
            RouteManager routes;

        int Q = 100'000; // number of requests
        int max_station_number = 1'000'000'000;
        for (int i = 0; i < Q; i++){
            routes.AddRoute(max_station_number, max_station_number);
        }
        {
            LOG_DURATION("GO with same number of stations");
            for (int i = 0; i < Q; i++){
                routes.FindNearestFinish(max_station_number, max_station_number);
            }
        }
    }
    {
        RouteManager routes;

        int Q = 100'000; // number of requests
        int max_station_number = 1'000'000'000;
        for (int i = 0; i < Q; i++){
            routes.AddRoute(max_station_number - i, max_station_number);
        }
        {
            LOG_DURATION("GO with different number of stations");
            for (int i = 0; i < Q; i++){
                routes.FindNearestFinish(max_station_number, max_station_number);
            }
        }
    }
}

void TestTimeAdd(){
    {
        RouteManager routes;

        int Q = 100'000; // number of requests
        int max_station_number = 1'000'000'000;
        {
            LOG_DURATION("ADD with zeros");
            for (int i = 0; i < Q; i++) {
                routes.AddRoute(i, 0);
            }
        }
    }
    {
        RouteManager routes;

        int Q = 100'000; // number of requests
        int max_station_number = 1'000'000'000;
        {
            LOG_DURATION("ADD with max number stations");
            for (int i = 0; i < Q; i++) {
                routes.AddRoute(i, max_station_number);
            }
        }
    }
    {
        RouteManager routes;

        int Q = 100'000; // number of requests
        int max_station_number = 1'000'000'000;
        {
            LOG_DURATION("ADD with different numbers of stations");
            for (int i = 0; i < Q; i++) {
                routes.AddRoute(max_station_number-i, i);
            }
        }
    }
}




int main2() {
  TestRunner tr;

  RUN_TEST(tr,TestCorrectness);
  RUN_TEST(tr, TestTimeAdd);
  RUN_TEST(tr, TestTimeGo);
  return 0;
}
int main() {
    RouteManager routes;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}
