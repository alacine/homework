#include <iostream>
#include <string>
using namespace std;

class Student {                                 //声明 Student 类
public:
    Student(int,string,float);                  //声明构造函数
    void display();                             //声明输出函数
private:
    int num;
    string name;
    float score;
};

Student::Student(int n, string nam, float s){   //定义构造函数
    num=n;
    name=nam;
    score=s;
}

void Student::display(){                        //定义输出函数
    cout << endl << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "score:" << score << endl;
}

class Graduate:public Student {                 //声明公用派生类 Graduate
public:
    Graduate(int, string, float, float);        //声明构造函数
    void display();                             //声明输出函数
private:
    float wage;                                 //津贴
};

Graduate::Graduate(int n, string nam, float s, float w):Student(n,nam,s),wage(w){}
                                                //定义构造函数
void Graduate::display(){                       //定义输出函数
    Student::display();                         //调用 Student 类的 display 函数
    cout << "wage=" << wage << endl;
}

int main(){
    Student stud1(1001,"Li",87.5);              //定义 Student 类对象stud1
    Graduate grad1(2001,"Wang",98.5,1000);      //定义 Graduate 类对象grad1
    Student *pt = &stud1;                       //定义指向 Student 类对象的指针并指向 stud1
    pt->display();                              //调用 stud1.display 函数
    pt = &grad1;                                //指针指向 grad1
    pt->display();                              //调用 grad1.display 函数
    return 0;
}

