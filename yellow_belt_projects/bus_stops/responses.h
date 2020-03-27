#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct StopsForBusResponse {
    vector<string> stops;
};

struct BusesForStopResponse {
    string buses;
};

struct AllBusesResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

ostream& operator << (ostream& os, const StopsForBusResponse& r);

ostream& operator << (ostream& os, const AllBusesResponse& r);