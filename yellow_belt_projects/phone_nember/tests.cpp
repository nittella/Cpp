#include "tests.h"

void TestPhoneNumber(){
  // correct number
    PhoneNumber("+7-916-6323088");
    PhoneNumber("+7-495-111-22-33");
    PhoneNumber("+323-22-460002");
    PhoneNumber("+1-2-coursera-cpp");
    // incorrect number
    try{
      PhoneNumber("1-2-333");
    }catch (invalid_argument& e){
      cerr << e.what() << endl;
    }
    try{
      PhoneNumber("+7-1233");
    }catch (invalid_argument& e){
      cerr << e.what() << endl;
    }
    //check GetCountryCode, GetCityCode, GetLocalNumber and GetInternationalNumber
    AssertEqual(PhoneNumber("+7-916-6323088").GetCountryCode(), "7", "hint_1");
    AssertEqual(PhoneNumber("+7-916-6323088").GetCityCode(), "916", "hint_2");
    AssertEqual(PhoneNumber("+7-916-6323088").GetLocalNumber(), "6323088", "hint_3");
    AssertEqual(PhoneNumber("+7-916-6323088").GetInternationalNumber(), "+7-916-6323088", "hint_4");
}

void TestAll(){
  TestRunner runner;
  runner.RunTest(TestPhoneNumber, "TestPhoneNumber");
}