#include "database.h"

void Database::Add(const Date& date, const string& event){
    if(db_set[date].count(event)==0){
        db_set[date].insert(event);
        db_vec[date].push_back(event);
    }
};

ostream& Database::Print(ostream& os) const {
    for (const auto& item : db_vec){
        for (const auto& event : item.second){
            os << item.first << " " << event << endl;
        }
    }
    return os;
};

pair<Date, string> Database::Last(const Date& date) const{
    if (db_set.empty() || (*begin(db_set)).first > date){
        throw invalid_argument("");
    }
    if(db_vec.count(date) != 0){
        int last_element = (db_vec.at(date)).size() - 1;
        return make_pair(date, (db_vec.at(date))[last_element]);
    } else {
        auto it = db_vec.upper_bound(date);
        it--;
        return make_pair(it->first, (it->second)[(it->second).size() - 1]);
    }
};