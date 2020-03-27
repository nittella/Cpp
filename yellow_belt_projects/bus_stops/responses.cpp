#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  os << r.buses;
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  bool no_first = false;
  for (const auto& i : r.stops){
    if (no_first){
      os << endl;
    }
    os << i;
    no_first = true;
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  bool no_first = false;
  for (const auto& i : r.buses){
    if (no_first){
      os << endl;
    }
    os << i;
    no_first = true;
  }
  return os;
}
