#include <iostream>
using namespace std;

class saleman
{
private:
	int num;
	int quantity;
	double price;
public:
	static double discount;
	static double sum;
	static int n;
	saleman(int a, int b, double c):num(a),quantity(b),price(c){}
	void getsum();
	static double average();
	static void display();
};

double saleman::discount=1;
double saleman::sum=0;
int saleman::n=0;

void saleman::getsum(){
	if(quantity<=10) discount=1;
	else discount=0.98;
	n++;
	sum+=quantity*price*discount;
}

double saleman::average(){
	return sum/n;
}

void saleman::display(){
	cout << sum << endl;
	cout << average() << endl;
}

int main()
{
	saleman sal[3]={saleman(101,5,23.5),saleman(102,12,24.56),saleman(103,100,21.5)};
	for (int i = 0; i < 3; ++i){
		sal[i].getsum();
	}
	saleman::display();
	return 0;
}