#include <iostream>
using namespace std;

class Time;
class Date
{
public:
	Date(int, int, int);
	friend Time;
private:
	int month;
	int day;
	int year;
};

class Time
{
public:
	Time(int, int, int);
	void display(Date &);
private:
	int hour;
	int minute;
	int sec;
};

Time::Time(int h, int m, int s){
	hour=h;
	minute=m;
	sec=s;
}


Date::Date(int m, int d, int y){
	month=m;
	day=d;
	year=y;
}

void Time::display(Date &d){
	cout << d.month << "/" << d.day << "/" << d.year << endl;
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main(int argc, char const *argv[])
{
	Time t1(10,13,56);
	Date d1(12,25,2004);
	t1.display(d1);
	return 0;
}