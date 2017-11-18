#include <iostream>
using namespace std;

class A
{
public:
    void f1();
    int i;
protected:
    void f2();
    int j;
private:
    int k;
};

class B: public A
{
public:
    coid f3();
protected:
    int m;
private:
    int n;
};

class C: public B
{
public:
    void f4();
protected:
    int p;
};

int main(int argc, char const *argv[])
{
    A a1;
    B b1;
    C c1;
    return 0;
}