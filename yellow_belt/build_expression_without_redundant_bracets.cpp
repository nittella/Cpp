#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ExpresionPart{
public:
    ExpresionPart(const char& operation, const int& number){
        number_ = number;
        operation_ = operation;
        if (operation == '*' || operation == '/'){
            operation_priority_ = 1;
        } else {
            operation_priority_ = 0;
        }
    }
    string GetOperation(){
        return string(1, operation_);
    }
    int GetOperationPriority(){
        return operation_priority_;
    }
    string GetNumber(){
        return to_string(number_);
    }

private:
    char operation_;
    int operation_priority_;
    int number_;
};

struct Expresion{
    int first_number;
    vector<ExpresionPart> expresion_parts;
};


ostream& operator<< (ostream& os, const Expresion& expresion){
    string result = to_string(expresion.first_number);
    int prev_operation_priority = 2;
    int brackets_number = 0;
    for (auto part : expresion.expresion_parts){
        if (part.GetOperationPriority() > prev_operation_priority){
            result +=") ";
            ++brackets_number;
        } else {
            result += " ";
        }
        result += part.GetOperation() + " " + part.GetNumber();
        prev_operation_priority = part.GetOperationPriority();
    }
    string brackets(brackets_number, '(');
    os << brackets << result;
    return os;

}

int main(){
    Expresion expresion;
    cin >> expresion.first_number;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        char operation;
        int number;
        cin >> operation;
        cin >> number;
        expresion.expresion_parts.push_back({operation, number});
    }
    cout << expresion;

    return 0;
}