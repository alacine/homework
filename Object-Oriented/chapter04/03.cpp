#include <iostream>
using namespace std;

class Complex {
  public:
    Complex() {}
    Complex(double r, double i): real(r), imag(i) {}
    Complex operator+(Complex &c);
    Complex operator+(int i);
    friend Complex operator+(int i, Complex &c);
    void display();
  private:
    double real, imag;
};

Complex Complex::operator+(Complex &c) {
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator+(int i) {
    return Complex(real + i, imag);
}

Complex operator+(int i, Complex &c) {
    return Complex(c.real + i, c.imag);
}

void Complex::display() {
    if(imag > 0) cout << real << "+" << imag << "i" << endl;
    else if(imag == 0) cout << real << endl;
    else cout << real << "-" << -imag << "i" << endl;
}

int main() {
    Complex a(100, 200);
    Complex b(50, 100);
    Complex c;
    c = a + b;
    cout << "a+b= " ;
    c.display();
    c = a + 1;
    cout << "a+1= ";
    c.display();
    c = 1 + a;
    cout << "1+a= ";
    c.display();
    return 0;
}