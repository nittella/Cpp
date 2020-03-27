#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>
#include <cassert>
using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string s;
  string operation_code;
  cin >> operation_code;
  if (operation_code == "NEW_BUS") {
    q.type = QueryType::NewBus;
    cin >> q.bus;
    int stop_count;
    cin >> stop_count;
    q.stops.resize(stop_count);
    for (string &stop : q.stops) {
      cin >> stop;
    }
  }else if (operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    cin >> q.stop;
  }
  else if (operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    cin >> q.bus;
  }
  else if (operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse {
    string response;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  os << r.response;
  return os;
}

struct StopsForBusResponse {
    string response;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  os << r.response;
  return os;
}

struct AllBusesResponse {
    string response;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  os << r.response;
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }
//  void TestAddBus(){
//    {
//      string bus = "1";
//      vector<string> stops = {"a", "b", "c"};
//
//    }
//  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    BusesForStopResponse r;
    r.response = "";
    if (stops_to_buses.count(stop) == 0) {
      r.response = "No stop";
    } else {
      int j = 0;
      for (const string &bus : stops_to_buses.at(stop)) {
        r.response += bus;
        if (j < stops_to_buses.at(stop).size()-1){
          r.response += " ";
        }
        j++;
      }
    }
    return r;
  }
  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse r;
    r.response = "";
    if (buses_to_stops.count(bus) == 0) {
      r.response = "No bus";
    } else {
      int i = 0;
      for (const string& stop : buses_to_stops.at(bus)) {
        r.response += "Stop " + stop +  ": ";
        if (stops_to_buses.at(stop).size() == 1) {
          r.response += "no interchange";
        } else {
          int j = 0;
          for (const string& other_bus : stops_to_buses.at(stop)) {
            if (bus != other_bus) {
              r.response += other_bus;
              if (j < stops_to_buses.at(stop).size()-1) {
                r.response += " ";
              }
              j++;
            }
          }
        }
        if (i < buses_to_stops.size()-1){
          r.response += '\n';
        }
        i++;
      }
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse r;
    r.response = "";
    if (buses_to_stops.empty()) {
      r.response += "No buses";
    } else {
      int i = 0;
      for (const auto& bus_item : buses_to_stops) {
        r.response += "Bus " + bus_item.first + ": ";
        int j = 0;
        for (const string& stop : bus_item.second) {
          r.response += stop;
          if (j < bus_item.second.size()-1) {
            r.response += " ";
          }
          j++;
        }
        if (i < buses_to_stops.size()-1){
          r.response += '\n';
        }
        i++;
      }
    }
    return r;
  }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
