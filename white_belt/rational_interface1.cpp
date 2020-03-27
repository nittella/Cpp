#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
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
      ChangeRational(numerator,denominator);
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }
    void ChangeRational(const int& numerator,const int& denominator){
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
  return {x.Numerator()*y.Denominator(), x.Denominator()*y.Numerator()};
}
istream& operator>>(istream& stream, Rational& x){
  if (!(stream.tellg() == -1)){
    int p, q;
    stream >> p;
    stream.ignore(1);
    stream >> q;
    x.ChangeRational(p,q);
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
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}