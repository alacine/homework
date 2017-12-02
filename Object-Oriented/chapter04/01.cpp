#include <iostream>
using namespace std;

class Complex {
  public:
    Complex() {}
    Complex(double r, double i): real(r), imag(i) {}
    double GetR() {return real;}
    double GetI() {return imag;}
    void display();
  private:
    double real, imag;
};

Complex operator+(Complex &c1, Complex &c2) {
    return Complex(c1.GetR() + c2.GetR(), c1.GetI() + c2.GetI());
}

void Complex::display() {
    if(imag > 0) cout << real << "+" << imag << "i" << endl;
    else if(imag == 0) cout << real << endl;
    else cout << real << "-" << -imag << "i" << endl;
}

int main() {
    Complex a(20, 20);
    Complex b(20, 30);
    Complex c = a + b;
    c.display();
    return 0;
}