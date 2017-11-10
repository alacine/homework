#include <iostream>
using namespace std;

class A {
public:
    A(){cout << "constructing A " << endl;}
    ~A(){cout << "destruting A " << endl;}
};

class B: public A {
public:
    B(){cout << "coustructing B " << endl;}
    ~B(){cout << "destructing B " << endl;}
};

class C: public B {
public:
    C(){cout << "coustructing C " << endl;}
    ~C(){cout << "destructing C " << endl;}
};

int main(){
    C c1;
    /*先调用A的构造函数,再调用B的构造函数,再调用C的构造函数
     *先调用C的析构函数,再调用B的析构函数,在调用A的析构函数
     */
    return 0;
}
