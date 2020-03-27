#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Stats {
public:
    Stats();
  void AddMethod(string_view method);
  void AddUri(string_view uri);
  const map<string_view, int>& GetMethodStats() const;
  const map<string_view, int>& GetUriStats() const;

private:
    map<string_view, int> methods_stats;
    map<string_view , int> uris_stats;
    vector<string> methods = {"GET", "POST", "PUT","DELETE", "UNKNOWN"};
    vector<string> uris = {"/", "/order", "/product", "/basket", "/help", "unknown"};


};

HttpRequest ParseRequest(string_view line);
