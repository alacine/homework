#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

class shape {
public:
    double area;
    virtual void printArea(){
        cout << area << endl;
    }


};

class Circle: public shape {
    double radius;
public:
    Circle(double r):radius(r) {
        area = radius * radius * PI;
    };
    virtual void shapeName()  {
        cout << "Circle" << endl;
    }
};

class Rectangle: public shape {
    double height,width;
public:
    Rectangle(double h, double w):height(h), width(w) {
        area = height * width;
    }
    virtual void shapeName()  {
        cout << "Rectangle" << endl;
    }
};

class Triangle: public shape {
    double a,b,c;
public:
    Triangle(double x, double y, double z):a(x), b(y), c(z) {
        double p = (a + b + c)/2.0;
        area = sqrt(p * (p-a) * (p-b) * (p-c));
    }
    virtual void shapeName() {
        cout << "Triangle" << endl;
    }
};

int main() {
    Circle c(5.0);
    c.printArea();
    Rectangle r(12.2, 20.3);
    r.printArea();
    Triangle t(5.0,12.0,13.0);
    t.printArea();
    return 0;
}
