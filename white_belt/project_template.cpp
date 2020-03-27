// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date(){
      Year = 0;
      Month = 1;
      Day = 1;
    }
    Date(const int& new_year,const int& new_month, const int& new_day){
      Year = new_year;
      Month = new_month;
      Day = new_day;
    }
  int GetYear() const{
    return Year;
  };
  int GetMonth() const{
    return Month;
  };
  int GetDay() const{
    return Day;
  };

private:
    int Year;
    int Month;
    int Day;
};

bool operator<(const Date& lhs, const Date& rhs){
  if (lhs.GetYear()<rhs.GetYear()){
    return true;
  } else if (lhs.GetYear()>rhs.GetYear()){
    return false;
  } else if (lhs.GetMonth()<rhs.GetMonth()){
    return true;
  } else if (lhs.GetMonth()>rhs.GetMonth()){
    return false;
  } else if (lhs.GetDay()<rhs.GetDay()) {
    return true;
  }
  return false;
  };
 istream& operator>> (istream& stream, Date& date){
   int year, month, day;
   char def1, def2;
   string saved_date;
   getline(stream, saved_date);
   stringstream saved_stream;
   saved_stream << saved_date;
   if(saved_stream >> year){
     if(saved_stream.peek()==EOF){
       throw invalid_argument(
               "Wrong date format: " + saved_date);
     }
       if(saved_stream.peek()==EOF){
         throw invalid_argument(
                 "Wrong date format: " + saved_date);
       }
        saved_stream >> def1;
       if (saved_stream >> month){
         if(saved_stream.peek()==EOF){
           throw invalid_argument(
                   "Wrong date format: " + saved_date);
         }
         saved_stream >> def2;
         if(saved_stream.peek()==EOF){
           throw invalid_argument(
                   "Wrong date format: " + saved_date);
         }
         if (saved_stream >> day){
           if(saved_stream.peek()!=EOF){
             throw invalid_argument(
                     "Wrong date format: " + saved_date);
           }
           if (def1 !='-' || def2 !='-'){
             throw invalid_argument("Wrong date format: " + saved_date);
           }
           if(month < 1 || month > 12 ){
             throw invalid_argument("Month value is invalid: " + to_string(month));
           }
           if(day < 1 || day > 31){
             throw invalid_argument("Day value is invalid: " + to_string(day));
           }
         } else {
           throw invalid_argument("Wrong date format: " + saved_date);
         }
       } else {
         throw invalid_argument("Wrong date format: " + saved_date);
       }
   } else {
     throw invalid_argument("Wrong date format: " + saved_date);
   };

   date = Date(year, month, day);
   return stream;
 };

 ostream& operator<< (ostream& stream, const Date& date){
   stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) <<date.GetMonth()<< '-' << setw(2) <<date.GetDay();
   return  stream;
 };

class Database {
public:
  void AddEvent(const Date& date, const string& event){
    database[date].insert(event);
  };
  bool DeleteEvent(const Date& date, const string& event){
    if (database.count(date)>0){
      if (database[date].count(event)>0){
        database[date].erase(event);
        return true;
      }
    }
    return false;
  };
  int  DeleteDate(const Date& date){
    int result = 0;
    if (database.count(date)>0){
      result = database[date].size();
      database.erase(date);
    }
    return result;
  };

  void Find(const Date& date) const{
    if (database.count(date)>0){
      for (const auto& item : database.at(date)){
        cout << item << endl;
      }
    }
  };

  void Print() const{
    for (const auto& i : database){
      for (const auto& j : i.second){
        cout << i.first << " " << j << endl;
      }
    }
  };

private:
    map<Date, set<string>> database;
};

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    stringstream ss;
    ss << command;
    string option;
    getline(ss, option, ' ');

    if (option == "Add"){
      getline(ss,option,' ');
      stringstream ss1;
      ss1 << option;
      Date date;
      try{
        ss1 >> date;
        getline(ss, option, ' ');
        db.AddEvent(date, option);
      } catch (invalid_argument& i_arg) {
        cout << i_arg.what() << endl;
//        return 0;
      }
    }

    else if (option == "Del"){
        getline(ss,option,' ');
        stringstream ss1;
        ss1 << option;
        Date date;
        try{
          ss1 >> date;
          if (ss.peek()==EOF){
            cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
          } else {
            getline(ss, option);
            if(db.DeleteEvent(date, option)){
              cout << "Deleted successfully" << endl;
            } else {
              cout << "Event not found" << endl;
            }
          }
        } catch (invalid_argument& i_arg) {
          cout << i_arg.what() << endl;
//          return 0;
        }

    }else if (option == "Find"){
      getline(ss,option,' ');
      stringstream ss1;
      ss1 << option;
      Date date;
      try{
        ss1 >> date;
        db.Find(date);
      } catch (invalid_argument& i_arg) {
        cout << i_arg.what() << endl;
//        return 0;
      }

    } else if (option == "Print"){
      db.Print();
    }

    else  if (!option.empty()){
      cout << "Unknown command: " << command << endl;
//      return 0;
    }
    // Считайте команды с потока ввода и обработайте каждую
  }
  return 0;
}