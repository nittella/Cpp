#include <deque>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>


#include "profile.h"
#include "test_runner.h"

using namespace std;

struct Request{
    int64_t time_;
    uint32_t hotel_number_;
    uint32_t client_id_;
    uint32_t room_count_;
};

class BookingManager{
public:

    BookingManager(){
        map<uint32_t , uint32_t > tmp_map = {};
        for (int i = 0; i <= MAX_REQUEST_COUNT_; i++){
            hotel_to_clients_.push_back(tmp_map);
            hotel_to_rooms_count_.push_back(0);
        }
    }


    void Book(int64_t time, string hotel_name, uint32_t client_id, uint32_t room_count){
        if (room_count != 0){
            uint32_t hotel_number;
            if(hotel_name_to_hotel_number_.find(hotel_name) == hotel_name_to_hotel_number_.end()){
                hotel_number = hotel_name_to_hotel_number_.size();
                hotel_name_to_hotel_number_.insert(make_pair(hotel_name, hotel_number));
            } else {
                hotel_number = hotel_name_to_hotel_number_.at(hotel_name);
            };
            requests_.push_back({time, hotel_number, client_id, room_count});
            if (hotel_to_clients_[hotel_number].find(client_id) == hotel_to_clients_[hotel_number].end()){
                hotel_to_clients_[hotel_number].insert({client_id, 1});
            } else {
                ++hotel_to_clients_[hotel_number][client_id];
            }
            hotel_to_rooms_count_[hotel_number] += room_count;

        }

        // clean from old requests
        int count = 0;
        for (auto request : requests_){

            if(request.time_ +  MAX_TIME_SAVED_ > time){
                break;
            }
            --hotel_to_clients_[request.hotel_number_][request.client_id_];
            if(hotel_to_clients_[request.hotel_number_][request.client_id_] <=0){
                hotel_to_clients_[request.hotel_number_].erase(request.client_id_);
            }
            hotel_to_rooms_count_[request.hotel_number_] -= request.room_count_;

            ++count;
        }

        for (int i = 0; i < count; i++){
            requests_.pop_front();
        }
    }

    int Clients(string hotel_name){
        if(hotel_name_to_hotel_number_.find(hotel_name) == hotel_name_to_hotel_number_.end()){
            return 0;
        } else {
            int hotel_number = hotel_name_to_hotel_number_.at(hotel_name);
            return hotel_to_clients_[hotel_number].size();
        };
    }

    int Rooms(string hotel_name){
        if(hotel_name_to_hotel_number_.find(hotel_name) == hotel_name_to_hotel_number_.end()){
            return 0;
        } else {
            int hotel_number = hotel_name_to_hotel_number_.at(hotel_name);
            return hotel_to_rooms_count_[hotel_number];
        };
    }


private:
    int MAX_REQUEST_COUNT_ = 100'000;
    int MAX_USER_COUNT_ = 1'000'000'000;
    int64_t MAX_TIME_SAVED_ = 86'400;

    map<string, uint32_t > hotel_name_to_hotel_number_; // max size 10^5
    deque<Request> requests_; // keep all requests here for one day
    vector<map<uint32_t, uint32_t>> hotel_to_clients_; // keep how much unique clients in each hotel
    vector<uint32_t > hotel_to_rooms_count_; // keep how much rooms are booked in each hotel

};



void TestBase(){
    istringstream ss("11\nCLIENTS Marriott\nROOMS Marriott\nBOOK 10 FourSeasons 1 2\nBOOK 10 Marriott 1 1\n"
                     "BOOK 86409 FourSeasons 2 1\nCLIENTS FourSeasons\nROOMS FourSeasons\nCLIENTS Marriott\n"
                     "BOOK 86410 Marriott 2 10\nROOMS FourSeasons\nROOMS Marriott");
    vector<int64_t> answers = {0, 0, 2, 3, 1, 1, 10};
    int answer_count = 0;
    BookingManager manager;
    uint32_t query_count;
    ss >> query_count;
     for (uint32_t i = 0; i < query_count; i++){
         string query_type;
         ss >> query_type;
         if(query_type == "BOOK"){
             int64_t time;
             string hotel_name;
             uint32_t client_id;
             uint32_t room_count;
             ss >> time >> hotel_name >> client_id >> room_count;
             manager.Book(time, hotel_name, client_id, room_count);

         } else if(query_type == "CLIENTS"){
             string hotel_name;
             ss >> hotel_name;
             ASSERT_EQUAL(manager.Clients(hotel_name), answers[answer_count]);
             ++answer_count;
         } else if(query_type == "ROOMS"){
             string hotel_name;
             ss >> hotel_name;
             ASSERT_EQUAL(manager.Rooms(hotel_name), answers[answer_count]);
             ++answer_count;
         }
     }

}

void Test(){
    {
        BookingManager manager;

        // Test empty bookings
        ASSERT_EQUAL(manager.Clients("mariott"), 0);
        ASSERT_EQUAL(manager.Rooms("mariott"), 0);

        manager.Book(0, "mariott", 1, 10);
        manager.Book(0, "mariott", 2, 1);
        manager.Book(0, "mariott", 3, 1);
        manager.Book(0, "mariott", 4, 1);
        manager.Book(0, "hilton", 1, 1);
        manager.Book(1, "hilton", 2, 1);

        // Test correctness
        ASSERT_EQUAL(manager.Clients("mariott"), 4);
        ASSERT_EQUAL(manager.Rooms("mariott"), 13);
        ASSERT_EQUAL(manager.Clients("hilton"), 2);
        ASSERT_EQUAL(manager.Rooms("hilton"), 2);

        // Test event past 1 day resets statics
        manager.Book(86400, "mariott", 1, 1);
        ASSERT_EQUAL(manager.Clients("mariott"), 1);
        ASSERT_EQUAL(manager.Rooms("mariott"), 1);
        ASSERT_EQUAL(manager.Clients("hilton"), 1);
        ASSERT_EQUAL(manager.Rooms("hilton"), 1);

        // Test no clients and room for the last day
        manager.Book(86401, "mariott", 5, 1);
        ASSERT_EQUAL(manager.Clients("mariott"), 2);
        ASSERT_EQUAL(manager.Rooms("mariott"), 2);
        ASSERT_EQUAL(manager.Clients("hilton"), 0);
        ASSERT_EQUAL(manager.Rooms("hilton"), 0);
    }

    {
        BookingManager manager;
        manager.Book(10, "Marriott", 1, 1);
        manager.Book(20, "Marriott", 1, 3);
        manager.Book(86410, "Marriott", 2, 3);
        ASSERT_EQUAL(manager.Rooms("Marriott"), 6);
        ASSERT_EQUAL(manager.Clients("Marriott"), 2);
    }
}

void TestTimeLimits(){
    BookingManager manager;
    int64_t  time1 = -1'000'000'000'000'000'000;
    uint32_t client_id1 = 1'000'000'000;
    string hotel_name1 = "abcdefghabcd";
    manager.Book(time1, hotel_name1, client_id1, 1'000);

    int64_t  time2 = -999'999'999'999'999'999;
    uint32_t client_id2 = 900'000'000;
    string hotel_name2 = "abcdefghabcd";
    manager.Book(time2, hotel_name2, client_id2, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name2), 2);
    ASSERT_EQUAL(manager.Rooms(hotel_name2), 2'000);

    int64_t  time3 = 0;
    uint32_t client_id3 = 0;
    string hotel_name3 = "abcdefghabcd";
    manager.Book(time3, hotel_name3, client_id3, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name3), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name3), 1'000);

    int64_t  time4 = 1'000'000'000'000'000'000 - 86399;
    uint32_t client_id4 = 0;
    string hotel_name4 = "abcdefghabcd";
    manager.Book(time4, hotel_name4, client_id4, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name4), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name4), 1'000);

    int64_t  time5 = 1'000'000'000'000'000'000;
    manager.Book(time5, hotel_name4, client_id4, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name4), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name4), 2'000);

    uint32_t client_id5 = 1;
    manager.Book(time5,hotel_name4, client_id5, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name4), 2);
    ASSERT_EQUAL(manager.Rooms(hotel_name4), 3'000);
}

void TestRoomsLimits(){
    BookingManager manager;
    for (int i = 0; i < 100'000; i++){
        manager.Book(0, "a", 1, 1'000);
    }
    ASSERT_EQUAL(manager.Clients("a"), 1);
    ASSERT_EQUAL(manager.Rooms("a"), 100'000'000);
}

void TestClientsLimits(){
    BookingManager manager;
    for (int i = 0; i < 100'000; i++){
        int current_client_id = 1'000'000'000 - i;
        manager.Book(0, "a", current_client_id, 1'000);
    }
    ASSERT_EQUAL(manager.Clients("a"), 100'000);
    ASSERT_EQUAL(manager.Rooms("a"), 100'000'000);
}


int main2(){
    TestRunner tr;
    RUN_TEST(tr, TestBase);
    RUN_TEST(tr, TestTimeLimits);
    RUN_TEST(tr, TestRoomsLimits);
    RUN_TEST(tr, TestClientsLimits);
    RUN_TEST(tr, Test);
    return 0;
}

int main(){
    BookingManager manager;
    uint32_t query_count;
    cin >> query_count;
    for (uint32_t i = 0; i < query_count; i++){
        string query_type;
        cin >> query_type;
        if(query_type == "BOOK"){
            int64_t time;
            string hotel_name;
            uint32_t client_id;
            uint32_t room_count;
            cin >> time >> hotel_name >> client_id >> room_count;
            manager.Book(time, hotel_name, client_id, room_count);

        } else if(query_type == "CLIENTS"){
            string hotel_name;
            cin >> hotel_name;
            cout << manager.Clients(hotel_name) << endl;
        } else if(query_type == "ROOMS"){
            string hotel_name;
            cin >> hotel_name;
            cout << manager.Rooms(hotel_name) << endl;
        }
    }
    return 0;
}