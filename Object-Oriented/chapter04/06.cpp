#include <iostream>
using namespace std;

class Complex {
  public:
    Complex(): real(0),imag(0) {}
    Complex(double r): real(r), imag() {}
    Complex(double r, double i): real(r), imag(i) {}
    operator double() {return real;}
    void display();
  private:
    double real, imag;
};

void Complex::display() {
    if(imag > 0) cout << real << "+" << imag << "i" << endl;
    else if(imag == 0) cout << real << endl;
    else cout << real << "-" << -imag << "i" << endl;
}

int main() {
    Complex a(1,2);
    double d = 2;
    double d1 = a + d;
    cout << "d1 = " << d1 << endl;
    Complex d2(d1);
    cout << "d2 = ";
    d2.display();
    return 0;
}