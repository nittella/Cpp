#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
    Rational() {  // дробь по умолчанию — 0/1
      numerator = 0;
      denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
      if (new_denominator == 0){
        throw invalid_argument("Invalid argument");
      }
      const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
      // сократим дробь, разделив числитель и знаменатель на их НОД
      numerator = new_numerator / gcd;
      denominator = new_denominator / gcd;
      // знаменатель должен быть положительным
      if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
      }
    }

    int Numerator() const {
      return numerator;
    }

    int Denominator() const {
      return denominator;
    }

private:
    int numerator;
    int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
         lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
          lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()
  };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
          lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
          lhs.Numerator() * rhs.Numerator(),
          lhs.Denominator() * rhs.Denominator()
  };
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator / (const Rational& lhs, const Rational& rhs) {
  if (rhs == Rational(0,1)){
    throw domain_error("Division by zero");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  is >> n >> c >> d;
  if (is && c == '/') {
    r = Rational(n, d);
  }
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}


int main() {
  Rational x, y;
  char operation;
  try {
    cin >> x >> operation >> y;
  } catch (invalid_argument& i_arg){
    cout << i_arg.what() << endl;
    return 0;
  }
  if (operation == '+'){
    cout << x+y << endl;
  }  else if (operation == '-'){
    cout << x-y << endl;
  } else if (operation == '*'){
    cout << x*y << endl;
  } else if (operation == '/'){
    try{
      Rational result = x/y;
      cout << result << endl;
    } catch (domain_error& d_err){
      cout << d_err.what() << endl;
      return 0;
    }
  }
  return 0;
}