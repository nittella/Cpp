#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
  string name;
  for (const auto& item : names) {
    if (item.first <= year) {
      name = item.second;
    } else {
      break;
    }
  }
  return name;
}

vector<string> ReverseVector(const vector<string>& v){
  vector<string> result;
  for (int i=v.size()-1; i>=0; i--){
    result.push_back(v[i]);
  }
  return result;
}

string FindHistoryByName(const map<int, string>& names, int year){
  vector<string> name_history_vector;
  string previous_name = "";
  string current_name = "";
  for (const auto& item : names) {
    if (item.first <= year) {
      current_name = item.second;
      if (current_name!=previous_name) {
        name_history_vector.push_back(item.second);
      }
      previous_name=current_name;
    }
  }
  vector<string> reverse_name_history_vector = ReverseVector(name_history_vector);
  if (name_history_vector.empty() || name_history_vector.size()==1){
    return "";
  } else {
    string result = " (";
    for (int i = 1; i<reverse_name_history_vector.size();i++){
        result+=reverse_name_history_vector[i];
        result+=", ";
    }
    result.erase(result.size()-1);
    result.erase(result.size()-1);
    result+=")";
    return result;
  }

}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
    }
    string GetFullName(int year) {
      const string first_name = FindNameByYear(first_names, year);
      const string last_name = FindNameByYear(last_names, year);
      if (first_name.empty() && last_name.empty()) {
        return "Incognito";
      } else if (first_name.empty()) {
        return last_name + " with unknown first name";
      } else if (last_name.empty()) {
        return first_name + " with unknown last name";
      } else {
        return first_name + " " + last_name;
      }
    }
    string GetFullNameWithHistory(int year) {
      const string first_name = FindNameByYear(first_names, year);
      const string last_name = FindNameByYear(last_names, year);
      const string first_name_history = FindHistoryByName(first_names, year);
      const string last_name_history = FindHistoryByName(last_names, year);
      if (first_name.empty() && last_name.empty()) {
        return "Incognito";
      } else if (first_name.empty()) {
        return last_name +last_name_history+ " with unknown first name";
      } else if (last_name.empty()) {
        return first_name+first_name_history + " with unknown last name";
      } else {
        return first_name+first_name_history + " " + last_name+last_name_history;
      }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};


int main(){

  return 0;
}