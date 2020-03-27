#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
  for (const string& stop : stops) {
    buses_for_stop[stop].push_back(bus);
    stops_for_bus[bus].push_back(stop);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
  BusesForStopResponse response;
  if (buses_for_stop.count(stop) == 0) {
    response.buses = "No stop";
  } else {
    for (const string& bus : buses_for_stop.at(stop)) {
      response.buses += bus + " ";
    }
  }
  return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
  StopsForBusResponse response;
  if (stops_for_bus.count(bus) == 0) {
    response.stops.push_back("No bus");
  } else {
    for (const string& stop : stops_for_bus.at(bus)) {
      string tmp;
      tmp = "Stop " + stop + ": ";
      if (buses_for_stop.at(stop).size() == 1) {
        tmp += "no interchange";
      } else {
        for (const string& other_bus : buses_for_stop.at(stop)) {
          if (bus != other_bus) {
            tmp += other_bus + " ";
          }
        }
      }
      response.stops.push_back(tmp);
    }
  }
  return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
  AllBusesResponse response;
  if (stops_for_bus.empty()) {
    response.buses.push_back("No buses");
  } else {
    for (const auto& bus_item : stops_for_bus) {
      string tmp;
      tmp += "Bus " + bus_item.first + ": ";
      for (const string& stop : bus_item.second) {
        tmp += stop + " ";
      }
      response.buses.push_back(tmp);
    }
  }
  return response;
}
