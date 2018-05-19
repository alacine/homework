#include <iostream>
using namespace std;

class Complex {
  public:
    Complex() {}
    Complex(double r, double i): real(r), imag(i) {}
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    Complex operator*(Complex &c);
    Complex operator/(Complex &c);
    void display();
  private:
    double real, imag;
};

Complex Complex::operator+(Complex &c) {
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(Complex &c) {
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(Complex &c) {
    return Complex(real * c.real + imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator/(Complex &c) {
    double tmp = c.real * c.real - c.imag * c.imag;
    return Complex((real * c.real - imag * c.imag)/tmp, (imag * c.real - real * c.imag)/tmp);
}

void Complex::display() {
    if(imag > 0) cout << real << "+" << imag << "i" << endl;
    else if(imag == 0) cout << real << endl;
    else cout << real << "-" << -imag << "i" << endl;
}

int main() {
    Complex a(1, 2);
    Complex b(3, -4);
    Complex c = a + b;
    c = a + b;
    c.display();
    c = a - b;
    c.display();
    c = a * b;
    c.display();
    c = a / b;
    c.display();
    return 0;
}