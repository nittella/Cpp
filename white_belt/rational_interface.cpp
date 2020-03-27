#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int FindGCF (const int& x, const int& y){
  int a,b;
  int result;
  if(x<y){
    a=x;
    b=y;
  }  else {
    a=y;
    b=x;
  }
  int j=2;
  bool n= false;
  for (int i=1; i<=j;i++){
    j=a/i;
    if (a%j==0 && b%j==0){
      result = j;
      n=true;
      break;
    }
  }
  if(!n){
    result = 1;
  }
  return result;
}

class Rational {
public:
    Rational() {
      p = 0;
      q = 1;
    }

    Rational(int numerator, int denominator) {
        ChangeRational(numerator, denominator);
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
        Reduce (p, q);
        p *= k;
      }
    }
private:
    int p;
    int q;
    void Reduce(int& x, int& y){
      int gcf = FindGCF(x,y);
      x /=gcf;
      y /= gcf;
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
Rational operator-(const Rational& x, const Rational& y){
  int lcd = x.Denominator()*y.Denominator()/FindGCF(x.Denominator(), y.Denominator());
  int a = lcd/x.Denominator();
  int b = lcd/y.Denominator();
  int nominator = a*x.Numerator() - b*y.Numerator();
  return {nominator, lcd};
}
Rational operator* (const Rational& x, const Rational& y){
  return {x.Numerator()*y.Numerator(), x.Denominator()*y.Denominator()};
}

Rational operator/ (const Rational& x, const Rational& y){
  return {x.Numerator()*y.Denominator(), x.Denominator()*y.Numerator()};
}

istream& operator>>(istream& stream, Rational& x){
  if (stream){
    int p, q;
    stream >> p;
    stream.ignore(1);
    stream >> q;
    x.ChangeRational(p,q);
    return stream;
  } else {
    int a = x.Numerator();
    int b = x.Denominator();
    x.ChangeRational(a, b);
    return cin;
  }
}
ostream& operator<<(ostream& stream, const Rational& x){
    stream << x.Numerator() << "/" << x.Denominator();
  return stream;
}

int main() {
  {
    const Rational r(-6, -1000000);
    if (r.Numerator() != 3  || r.Denominator() != 500000) {
      cout << "Rational(3, 10) != 3/10" << endl;
      system("pause");
      return 1;
    }
  }

  {
    const Rational r(8000, 12000);
    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(8, 12) != 2/3" << endl;
      system("pause");
      return 2;
    }
  }

  {
    const Rational r(-4000, 6000);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(-4, 6) != -2/3" << endl;
      system("pause");
      return 3;
    }
  }

  {
    const Rational r(4000, -6000);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(4, -6) != -2/3" << endl;
      system("pause");
      return 3;
    }
  }

  {
    const Rational r(0, 15000);
    if (r.Numerator() != 0 || r.Denominator() != 1) {
      cout << "Rational(0, 15) != 0/1" << endl;
      system("pause");
      return 4;
    }
  }

  {
    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
      cout << "Rational() != 0/1" << endl;
      system("pause");
      return 5;
    }
  }

  cout << "OK" << endl;
  return 0;
}