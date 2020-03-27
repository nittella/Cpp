#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

//class Passport{
//public:
//    void ChangeFirstName(const string& s){
//      first_name = s;
//    }
//    void ChangeLastName(const string& s){
//      last_name = s;
//    }
//    vector<string> GetFullNameVector(){
//      vector<string> full_name;
//      full_name.push_back(first_name);
//      full_name.push_back(last_name);
//      return full_name;
//    }
//private:
//    string first_name = "unknown";
//    string last_name = "unknown";
//};

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
      first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
      last_names[year] = last_name;
    }

    string GetFullName(int year) {
      string first_name = "";
      string last_name = "";
      string result;
      for (auto item : first_names){
        if (item.first>year){
          break;
        } else {
          first_name = item.second;
        }
      }
      for (auto item : last_names){
        if (item.first>year){
          break;
        } else {
          last_name = item.second;
        }
      }

      if(first_name !=""&& last_name!=""){
        result=first_name+" "+last_name;
      } else if (first_name=="" && last_name!=""){
        result = last_name + " with unknown first name";
      }else if (last_name=="" && first_name !=""){
        result = first_name + " with unknown last name";
      } else {
        result = "Incognito";
      }
      return result;

    }
    string GetFullNameWithHistory(int year) {
      string first_name = "";
      vector<string> first_name_history;
      string last_name = "";
      string last_name_history = "";
      string result;
      for (auto item : first_names){
        if (item.first>year){
          break;
        } else {
          if (first_name != item.second){
            first_name = item.second;
            if (item.first!=year){
              first_name_history+=item.second;
              first_name_history+=", ";
            }
          }

        }
      }
      for (auto item : last_names){
        if (item.first>year){
          break;
        } else {
          if (last_name != item.second){
            last_name = item.second;
            if (item.first!=year){
              last_name_history+=item.second;
              last_name_history+=", ";
            }
          }
        }
      }
      if (first_name_history!=""){
        first_name_history.erase(first_name_history.size()-1);
        first_name_history.erase(first_name_history.size()-1);
        first_name_history = " ("+first_name_history+")";
      }


      if(first_name !=""&& last_name!=""){
        result=first_name+first_name_history+" "+last_name;
      } else if (first_name=="" && last_name!=""){
        result = last_name + " with unknown first name";
      }else if (last_name=="" && first_name !=""){
        result = first_name +first_name_history+ " with unknown last name";
      } else {
        result = "Incognito";
      }
      return result;

    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}