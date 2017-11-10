#include <iostream>
using namespace std;

class A{
public:
    A(){a=0;b=0;}
    A(int i){a=i;b=0;}
    A(int i, int j){a=i;b=j;}
    void display(){
        cout << "a=" << a << "b=" << b;
    }
private:
    int a;
    int b;
};

class B: public A{  //定义B类为A的公有继承类
public:
    B(){c=0;}
    B(int i):A(i){c=0;}
    B(int i, int j):A(i,j){c=0;}
    B(int i, int j, int k):A(i,j){c=k;}
    void display1(){
        display();
        cout << "c=" << c << endl;
    }
private:
    int c;
};

int main(){
    B b1;           //先调用a的第1个构造函数,再调用b的第1个构造函数
    B b2(1);        //先调用a的第2个构造函数,再调用b的第2个构造函数
    B b3(1,3);      //先调用a的第3个构造函数,再调用b的第3个构造函数
    B b4(1,3,5);    //先调用a的第3个构造函数,再调用b的第4个构造函数
    b1.display1();  //输出
    b2.display1();  //输出
    b3.display1();  //输出
    b4.display1();  //输出
    return 0;
}
