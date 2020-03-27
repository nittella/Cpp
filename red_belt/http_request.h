#pragma once

#include <string_view>
#include <vector>
using namespace std;

struct HttpRequest {
  string_view method, uri, protocol;
};



