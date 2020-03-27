#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

#include "date.h"

using namespace std;

struct DateEvent{
    Date date;
    string event;
};

bool operator< (const DateEvent& lhs, const DateEvent& rhs){
    return lhs.date < rhs.date;
}
bool operator== (const DateEvent& lhs, const DateEvent& rhs){
    return lhs.date == rhs.date && lhs.event == rhs.event;
}

int main() {
    Date date1  = Date(2017, 1, 1);
    Date date2  = Date(2017, 3, 8);
    Date date3  = Date(2018, 3, 8);
    DateEvent de1 = {date1, "b"};
    DateEvent de2 = {date1, "a"};
    DateEvent de3 = {date1, "c"};
    DateEvent de4 = {date1, "a"};
    set<DateEvent> s({{date1, "b"}, {date1, "a"}, {date1, "c"}, {date2, "a"}});

    for (auto item : s){
        cout << item.date << " " << item.event << endl;
    }

    return 0;
}