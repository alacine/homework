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
    /*�ȵ���A�Ĺ��캯��,�ٵ���B�Ĺ��캯��,�ٵ���C�Ĺ��캯��
     *�ȵ���C����������,�ٵ���B����������,�ڵ���A����������
     */
    return 0;
}
