#include "Point.cpp"

int main(int argc, char const *argv[])
{
	Point p(3.5, 6.4);
	cout << "x = " << p.getX() << ", y = " << p.getY() << endl;
	p.setPoint(8.5, 6.8);
	cout << "p(new): " << p << endl;
	return 0;
}