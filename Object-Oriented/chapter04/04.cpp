#include <iostream>
using namespace std;

class Matrix {
  public:
    Matrix() {}
    Matrix(double s[][3]);
    Matrix operator+(Matrix &m);
    void display();
  private:
    double num[2][3];
};

Matrix::Matrix(double s[][3]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            num[i][j] = s[i][j];
        }
    }
}

Matrix Matrix::operator+(Matrix &m) {
    Matrix c;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            c.num[i][j] = num[i][j] + m.num[i][j];
        }
    }
    return c;
}

void Matrix::display() {
    for(int i = 0; i < 2 ; i++) {
        for(int j = 0; j < 3; j++) {
            cout << num[i][j] << " " ;
        }
        cout << endl;
    }
}

int main() {
    double a[2][3] = {{1,2,3},{4,5,6}};
    double b[2][3] = {{7,8,9},{10,11,12}};
    Matrix m1(a);
    Matrix m2(b);
    Matrix m3 = m1 + m2;
    m3.display();
    return 0;
}