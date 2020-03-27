#pragma once

#include <iostream>
#include <sstream>
#include <string_view>


using namespace std;

istringstream GetSubString(string_view& source);

template <typename T>
T GetFromString(string_view& source){
    istringstream s = GetSubString(source);
    T result;
    s >> result;
    return result;
}