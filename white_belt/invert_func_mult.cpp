#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FunctionPart{
public:
    FunctionPart(char new_operation, double new_value){
      operation = new_operation;
      value = new_value;
    }
    double Apply(double source_value)const {
      if (operation == '+'){
        source_value+=value;
      }else if (operation == '-'){
        source_value-=value;
      } else if( operation=='*'){
        source_value*=value;
      } else {
        source_value/=value;
      }
      return source_value;
    }
    void Invert(){
      if (operation == '+'){
        operation='-';
      }else if (operation == '-'){
        operation='+';
      } else if( operation=='*'){
        operation='/';
      } else {
        operation='*';
      }
    }

private:
    char operation;
    double value;
};
class Function{
public:
    void AddPart(const char& new_operation, double new_value){
      parts.push_back({new_operation, new_value});
    }
    double Apply(double value)const{
      for(const auto& part : parts){
        value = part.Apply(value);
      }
      return value;
    }
    void Invert(){
      for (FunctionPart& part : parts){
        part.Invert();
      }
      reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

int main() {
  return 0;
}
