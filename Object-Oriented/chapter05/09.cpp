#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
	Teacher(string na,int a,char s,string ad,string tel,string tit);
	void display();
	string name;
	int age;
	char sex;
	string addr;
	string tele;
	string title;
};
Teacher::Teacher(string na,int a,char s,string ad,string tel,string tit):
name(na),age(a),sex(s),addr(ad),tele(tel),title(tit){}
void Teacher::display(){
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "title:" << title << endl;
	cout << "address:" << addr << endl;
	cout << "telephone:" << tele << endl;
}

class Cadre
{
public:
	Cadre(string na,int a,char s,string ad,string tel,string po);
	string name;
	int age;
	char sex;
	string addr;
	string tele;
	string post;
};
Cadre::Cadre(string na,int a,char s,string ad,string tel,string po):
name(na),age(a),sex(s),addr(ad),tele(tel),post(po){}

class Teacher_Cadre: public Teacher, public Cadre
{
public:
	Teacher_Cadre(string na,int a,char s,string ad,string tel,string tit,string po,int wa);
	int wages;
	void show();
};
Teacher_Cadre::Teacher_Cadre(string na,int a,char s,string ad,string tel,string tit,string po,int wa):
Teacher(na,a,s,ad,tel,tit),Cadre(na,a,s,ad,tel,po),wages(wa){}

void Teacher_Cadre::show(){
	display();
	cout << "post:" << Cadre::post << endl;
	cout << "wages:" << wages << endl;
}

int main()
{
	Teacher_Cadre t1("Ms Wang",30,'f',"china","11122223333","math teacher","leader",3000);
	t1.show();
	return 0;
}
