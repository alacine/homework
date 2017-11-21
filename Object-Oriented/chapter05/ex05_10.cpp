#include <iostream>
#include <string>
using namespace std;

class Student {                                 //���� Student ��
public:
    Student(int,string,float);                  //�������캯��
    void display();                             //�����������
private:
    int num;
    string name;
    float score;
};

Student::Student(int n, string nam, float s){   //���幹�캯��
    num=n;
    name=nam;
    score=s;
}

void Student::display(){                        //�����������
    cout << endl << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "score:" << score << endl;
}

class Graduate:public Student {                 //�������������� Graduate
public:
    Graduate(int, string, float, float);        //�������캯��
    void display();                             //�����������
private:
    float wage;                                 //����
};

Graduate::Graduate(int n, string nam, float s, float w):Student(n,nam,s),wage(w){}
                                                //���幹�캯��
void Graduate::display(){                       //�����������
    Student::display();                         //���� Student ��� display ����
    cout << "wage=" << wage << endl;
}

int main(){
    Student stud1(1001,"Li",87.5);              //���� Student �����stud1
    Graduate grad1(2001,"Wang",98.5,1000);      //���� Graduate �����grad1
    Student *pt = &stud1;                       //����ָ�� Student ������ָ�벢ָ�� stud1
    pt->display();                              //���� stud1.display ����
    pt = &grad1;                                //ָ��ָ�� grad1
    pt->display();                              //���� grad1.display ����
    return 0;
}
