#include <iostream>
#include <string>
using namespace std;

class Person {                          //下面声明公共基类 Person
public:
    Person(string nam, char s,int a){   //构造函数
        name=nam;
        sex=s;
        age=a;
    }
protected:                              //保护成员
    string name;
    char sex;
    int age;
};

class Teacher:virtual public Person {   //声明 Person 为公用继承的虚基类
public:
    Teacher(string nam, char s, int a, string t):Person(nam,s,a){//构造函数
        title=t;
    }
protected:                              //保护成员
    string title;                       //职称
};

class Student:virtual public Person {   //声明 Person 为公用继承的虚基类
public:
    Student(string nam, char s, int a, float sco)//构造函数
        :Person(nam,s,a),score(sco){}   //初始化表
protected:                              //保护成员
    float score;                        //成绩
};

class Graduate:public Teacher, public Student {//Teacher 和 Student 为直接基类
public:
    Graduate(string nam, char s, int a, string t, float sco, float w)//构造函数
        :Person(nam,s,a),Teacher(nam,s,a,t),Student(nam,s,a,sco),wages(w){}
                                        //初始化表
    void show(){                        //输出研究生的有关数据
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "sex:" << sex << endl;
        cout << "score:" << score << endl;
        cout << "title:" << title << endl;
        cout << "wages:" << wages << endl;
    }
private:
    float wages;
};

int main(){
    Graduate grad1("Wang_li",'f',24,"assistant",89.5,1200);
    grad1.show();
    return 0;
}
