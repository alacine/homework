#include <iostream>
#include <string>
using namespace std;

class Teacher{
public:
    Teacher();
    Teacher(int n,string na,char s):num(n),name(na),sex(s){}
    void display(){
        cout << "num:" << num << endl;
        cout << "name:" << name << endl;
        cout << "sex:" << sex << endl;
    }
private:
    int num;
    string name;
    char sex;
};

class BirthDate{
public:
    BirthDate();
    BirthDate(int a, int b, int c):year(a),month(b),day(c){}
    void display(){
        cout << year << "/" << month << "/" << day << endl;
    }
    edit(int a, int b, int c){
        year=a;
        month=b;
        day=c;
    }
private:
    int year;
    int month;
    int day;
};

class Professor: public Teacher{
private:
    BirthDate birthday;
public:
    Professor(int a,int b,int c,int n,string na,char s):birthday(a,b,c),Teacher(n,na,s){}
    void show(){
        display();
        birthday.display();
    }
    void edit(int a,int b, int c){
        birthday.edit(a,b,c);
    }
};

int main(){
    Professor prof1(2000,1,1,1,"Tom",'m');
    prof1.show();
    prof1.edit(2001,2,2);
    cout << "after edit:" << endl;
    prof1.show();
    return 0;
}
