#pragma once;

#include <sstream>


void TestBase(){
    istringstream ss("11\nCLIENTS Marriott\nROOMS Marriott\nBOOK 10 FourSeasons 1 2\nBOOK 10 Marriott 1 1\n"
                     "BOOK 86409 FourSeasons 2 1\nCLIENTS FourSeasons\nROOMS FourSeasons\nCLIENTS Marriott\n"
                     "BOOK 86410 Marriott 2 10\nROOMS FourSeasons\nROOMS Marriott");
    vector<int64_t> answers = {0, 0, 2, 3, 1, 1, 10};
    int answer_count = 0;
    BookingManager manager;
    int query_count;
    ss >> query_count;
    for (int i = 0; i < query_count; i++){
        string query_type;
        ss >> query_type;
        if(query_type == "BOOK"){
            int time;
            string hotel_name;
            int client_id;
            int room_count;
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

void TestLimits(){
    BookingManager manager;
    int64_t  time1 = -1'000'000'000'000'000'000;
    int client_id1 = 1'000'000'000;
    string hotel_name1 = "abcdefghabcd";
    manager.Book(time1, hotel_name1, client_id1, 1'000);

    int64_t  time2 = -999'999'999'999'999'999;
    int client_id2 = 900'000'000;
    string hotel_name2 = "abcdefghabcd";
    manager.Book(time2, hotel_name2, client_id2, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name2), 2);
    ASSERT_EQUAL(manager.Rooms(hotel_name2), 2'000);

    int64_t  time3 = 0;
    int client_id3 = 0;
    string hotel_name3 = "abcdefghabcd";
    manager.Book(time3, hotel_name3, client_id3, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name3), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name3), 1'000);

    int64_t  time4 = 1'000'000'000'000'000'000;
    int client_id4 = 0;
    string hotel_name4 = "abcdefghabcd";
    manager.Book(time4, hotel_name4, client_id4, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name4), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name4), 1'000);

    int64_t  time5 = 1'000'000'000'000'000'001;
    manager.Book(time5, hotel_name4, client_id4, 1'000);
    ASSERT_EQUAL(manager.Clients(hotel_name4), 1);
    ASSERT_EQUAL(manager.Rooms(hotel_name4), 2'000);
}