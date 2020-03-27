#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int FindGCF (int a, int b){
  while (a > 0 && b > 0) {
    // возьмём большее из чисел и заменим его остатком от деления на второе
    // действительно, если a и b делятся на x, то a - b и b делятся на x
    // тогда и a % b и b делятся на x, так что можно a заменить на a % b
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  // если одно из чисел оказалось равно нулю, значит, на последней итерации
  // большее число разделилось на меньшее
  return a + b;
}

class Rational {
public:
    Rational() {
      p = 0;
      q = 1;
    }

    Rational(int numerator, int denominator) {
      if (denominator == 0){
        throw invalid_argument("Denominator must not be 0.");
      }
      p = numerator;
      q = denominator;
      if (p==0){
        q = 1;
      } else {
        int k = 1;
        if (p < 0){
          p *=-1;
          k *=-1;
        }
        if (q < 0) {
          q *=-1;
          k *=-1;
        }
        Reduce ();
        p *= k;
      }
    }

    int Numerator() const {
      return p;
    }

    int Denominator() const {
      return q;
    }
private:
    int p;
    int q;
    void Reduce(){
      int gcf = FindGCF(abs(p), abs(q));
      p /= gcf;
      q /= gcf;
    }

};

bool operator==(const Rational&x, const Rational& y){
  if(x.Numerator()==y.Numerator() && x.Denominator() == y.Denominator()){
    return true;
  } else {
    return false;
  }
}
Rational operator+ (const Rational& x, const Rational& y){
  int lcd = x.Denominator()*y.Denominator()/FindGCF(x.Denominator(), y.Denominator());
  int a = lcd/x.Denominator();
  int b = lcd/y.Denominator();
  int nominator = a*x.Numerator() + b*y.Numerator();
  return {nominator, lcd};
}
Rational operator-(const Rational& x, const Rational& y) {
  int lcd = x.Denominator() * y.Denominator() / FindGCF(x.Denominator(), y.Denominator());
  int a = lcd / x.Denominator();
  int b = lcd / y.Denominator();
  int nominator = a * x.Numerator() - b * y.Numerator();
  return {nominator, lcd};
}
Rational operator* (const Rational& x, const Rational& y){
  return {x.Numerator()*y.Numerator(), x.Denominator()*y.Denominator()};
}

Rational operator/ (const Rational& x, const Rational& y){
  if (y == Rational(0,1)){
    throw domain_error("Can't divide on zero");
  }
  return {x.Numerator()*y.Denominator(), x.Denominator()*y.Numerator()};
}
istream& operator>>(istream& stream, Rational& x){
  if (!(stream.tellg() == -1)){
    int p, q;
    stream >> p;
    stream.ignore(1);
    stream >> q;
    x = Rational(p,q);
    return stream;
  } else {
    return stream;
  }
}
ostream& operator<<(ostream& stream, const Rational& x){
  stream << x.Numerator() << "/" << x.Denominator();
  return stream;
}
bool operator< (const Rational& lhs, const Rational& rhs){
  return (lhs - rhs).Numerator()<0;
};

int main() {
  try {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  } catch (invalid_argument&) {
    int i = 1;
  }

  try {
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  } catch (domain_error&) {
  }

  cout << "OK" << endl;
  return 0;
}