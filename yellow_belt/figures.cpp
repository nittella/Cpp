#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure{
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Rect : public Figure{
public:
    Rect(const int& width, const int& height) : width_(width), height_(height){};
    string Name() {
        return "RECT";
    }
    double Perimeter() override {
        double perimeter = 2 * (width_ + height_);
        return perimeter;
    }
    double Area() override {
        double area = width_ * height_;
        return area;
    }

private:
    int width_;
    int height_;
};

class Triangle : public Figure{
public:
    Triangle(const int& a, const int& b, const int& c) : a_(a), b_(b), c_(c) {}
    string Name() override {
        return "TRIANGLE";
    }
    double Perimeter() override {
        double perimeter = a_ + b_ + c_;
        return perimeter;
    }
    double Area() override {
        double s = Perimeter() / 2;
        double area = sqrt(s * (s - a_) * (s - b_) * (s - c_));
        return area;
    }

private:
    int a_;
    int b_;
    int c_;
};

class Circle : public Figure{
public:
    Circle(const int& r) : r_(r) {}
    string Name() override {
        return "CIRCLE";
    }
    double Perimeter() override {
        double perimeter = 2 * 3.14 * r_;
        return perimeter;
    }
    double Area() override {
        double area = 4 / 3 * 3.14 * pow(r_, 2);
        return area;
    }

private:
    int r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string figure;
    is >> figure;
    if (figure == "RECT"){
        int width, height;
        is >> width >> height;
        return make_shared<Rect>(Rect(width, height));
    } else if (figure == "TRIANGLE"){
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(Triangle(a, b, c));
    } else if (figure == "CIRCLE"){
        int r;
        is >> r;
        return make_shared<Circle>(Circle(r));
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}