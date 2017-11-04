#include <iostream>
#include <string>
using namespace std;

class base
{
public:
	string name;
	int age;
	char sex;
	string addr;
	string number;
};

class Teacher: public 
{
public:
	Teacher();
	~Teacher();
	
};

class Cadre
{
public:
	Cadre();
	~Cadre();
	
};

class Teacher_Cadre: public Teacher, public Cadre
{
	if
};