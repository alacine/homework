#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

class Shape
{
public:
    virtual double area() const {
        return 0.0;
    }
};

class Circle: public Shape 
{
    double radius;
public:
    Circle(double r):radius(r) {};
    double area() const {
        return radius * radius * PI;
    }
};

class Rectangle: public Shape
{
    double height,width;
public:
    Rectangle(double h, double w):height(h), width(w) {}
    double area() const {
        return height * width;
    }
};

class Triangle: public Shape
{
    double a,b,c;
public:
    Triangle(double x, double y, double z):a(x), b(y), c(z) {}
    double area() const {
        double p = (a + b + c)/2.0;
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }
};

void printArea(const Shape &s) {
    cout << s.area() << endl;
}

int main() {
    Circle c(5.0);
    cout << "Circle:" << endl;
    printArea(c);
    Rectangle r(12.2, 20.3);
    cout << "\nRectangle:" << endl;
    printArea(r);
    Triangle t(5.0,12.0,13.0);
    cout << "\nTriangle:" << endl;
    printArea(t);
    return 0;
}
