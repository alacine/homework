#include "Circle.cpp"

int main(int argc, char const *argv[])
{
	Circle c(3.5, 6.4, 5.2);
	cout << "original circle:\nx = " << c.getX() << ", y = " << c.getY() << ", r = "
	<< c.getRadius() << ", area = " << c.area() << endl;
	c.setRadius(7.5);
	c.setPoint(5,5);
	cout << "new circle:\n" << c;
	Point &pRef = c;
	cout << "pRef:" << pRef;
	return 0;
}
