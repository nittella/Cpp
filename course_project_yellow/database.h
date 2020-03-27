#pragma once

#include "date.h"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Database{
public:

    void Add(const Date& date, const string& event);

    ostream& Print(ostream& os) const;

    template <typename Function>
    int RemoveIf(Function predicate){
        int objects_removed = 0;
        vector<Date> keys_for_del;
        for (auto it = begin(db_vec); it != end(db_vec);){
            auto it_remove = stable_partition(begin(it->second), end(it->second),
                    [predicate, it](const string& event){ return !predicate(it->first, event);});
            if (it_remove != end(it->second)){
                auto it_remove_set = end(it->second);
                do{
                    it_remove_set--;
                    db_set[it->first].erase(*it_remove_set);
                    objects_removed++;
                } while (it_remove_set != it_remove);
            }
            size_t new_size = it_remove - begin(it->second);
            it->second.resize(new_size);
            if((it->second).empty()){
                keys_for_del.push_back(it->first);
            }
            it++;
        }
        for (auto key : keys_for_del){
            db_vec.erase(key);
            db_set.erase(key);
        }
        return objects_removed;
    };

    template <typename Function>
    vector<pair<Date, string>> FindIf(Function predicate) const {
        vector<pair<Date, string>> result;
        for (const auto& item : db_vec){
            for (const auto& event : item.second){
                if(predicate(item.first, event)){
                    result.push_back(make_pair(item.first, event));
                }
            }
        }
        return result;
    };

    pair<Date, string> Last(const Date& date) const;

private:
    map<Date, vector<string>> db_vec;
    map<Date, set<string>> db_set;
};
