#include "phone_number.h"
#include <string>
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number) {
  stringstream ss;
  ss << international_number;
  bool correct_format = true;
  if (ss.peek()!='+'){
    correct_format = false;
  }
  ss.ignore(1);
  getline(ss, country_code_, '-');
  if(ss.peek() == EOF){
    correct_format = false;
  }
  getline(ss, city_code_, '-');
  if(ss.peek() == EOF){
    correct_format = false;
  }
  getline(ss, local_number_);
  if (!correct_format){
    throw invalid_argument("invalid_argument: " + international_number);
  }
}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
};

string PhoneNumber::GetCityCode() const{
  return city_code_;
};

string PhoneNumber::GetLocalNumber() const{
  return local_number_;
};

string PhoneNumber::GetInternationalNumber() const{
  return "+" + country_code_ + "-" + city_code_+ "-" + local_number_;
};