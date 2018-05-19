#include <iostream>
using namespace std;

class Cuboid{
private:
    double length;
    double width;
    double height;
    double volume;
public:
    void set_cuboid(double a,double b,double c){
        length=a;
        width=b;
        height=c;
    }
    void get_volume(){
        volume = length*width*height;
        cout<<volume;
    }
};

int main(){
    double x,y,z;
    Cuboid R1;
    cin>>x>>y>>z;
    R1.set_cuboid(x,y,z);
    R1.get_volume();
    return 0;
}
