#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

class Shape
{
public:
    virtual double area() const {return 0.0;}
};

class Circle: public Shape
{
    double radius;
public:
    Circle(double r):radius(r) {};
    virtual double area() const {
        return radius * radius * PI;
    }
};

class Square: public Shape
{
    double side;
public:
    Square(double s):side(s) {}
    virtual double area() const {
        return side * side;
    }
};

class Rectangle: public Shape
{
    double height,width;
public:
    Rectangle(double h, double w):height(h), width(w) {}
    virtual double area() const {
        return height * width;
    }
};

class Trapezoid: public Shape
{
    double top, bottom, height;
public:
    Trapezoid(double t, double b, double h):top(t), bottom(b), height(h) {}
    virtual double area() const {
        return (top + bottom) * height / 2.0;
    }
};

class Triangle: public Shape
{
    double a,b,c;
public:
    Triangle(double x, double y, double z):a(x), b(y), c(z) {}
    virtual double area() const {
        double p = (a + b + c)/2.0;
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }
};



void printArea(const Shape &s) {
    cout << s.area() << endl;
}

int main() {
    Circle c(5.0);
    Square s(7.1);
    Rectangle r(12.2, 20.3);
    Trapezoid t(3.4, 4.4, 5.3);
    Triangle tri(5.0,12.0,13.0);
    Shape *sh[5]={&c, &s, &r, &t, &tri};
    double areaSum = 0.0;
    for (int i = 0; i < 5; ++i) {
        cout << sh[i]->area() << endl;
        areaSum += sh[i]->area();
    }
    cout << "Sum = " << areaSum << endl;
    return 0;
}
