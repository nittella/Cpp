#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ExpresionPart{
    char operation;
    int number;
};

struct Expresion{
    int first_number;
    vector<ExpresionPart> expresion_parts;
};

ostream& operator<< (ostream& os, const Expresion& expresion){
    string result(expresion.expresion_parts.size(), '(');
    result += to_string(expresion.first_number);
    for (auto part : expresion.expresion_parts){
        result += ") " + string(1, part.operation) +
                ' ' + to_string(part.number);
    }
    os << result;
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