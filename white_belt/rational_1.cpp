#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
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
    int FindGCF (const int& x, const int& y){
        int a,b;
        if(x<y){
            a=x;
            b=y;
        }  else {
            a=y;
            b=x;
        }
        int j=2;
        bool n= false;
        int result = 1;
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
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
      const Rational r(6, 3);
      if (r.Numerator() != 2 || r.Denominator() != 1) {
        cout << "Rational(6, 3) != 2/1" << endl;
        return 1;
      }
    }

  {
    const Rational r(-6, 3);
    if (r.Numerator() != -2 || r.Denominator() != 1) {
      cout << "Rational(-6, 3) != -2/1" << endl;
      return 1;
    }
  }

  {
    const Rational r(-6, -3);
    if (r.Numerator() != 2 || r.Denominator() != 1) {
      cout << "Rational(-6, -3) != 2/1" << endl;
      return 1;
    }
  }

  {
    const Rational r(6, -3);
    if (r.Numerator() != -2 || r.Denominator() != 1) {
      cout << "Rational(6, -3) != -2/1" << endl;
      return 1;
    }
  }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
