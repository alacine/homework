#include <iostream>
#include <algorithm>
using namespace std;

class Student{
public:
    Student(){}
    Student(int a,int b):id(a),score(b){}
    int id;
    int score;
};
Student student[5];

bool cmp(Student a, Student b){
    return a.score > b.score;
}

void max(Student *p){
    sort(p,p+4,cmp);
    cout << p[0].id << " " << p[0].score << endl;
}

int main()
{
    student[0]=Student(1,70);
    student[1]=Student(2,80);
    student[2]=Student(3,100);
    student[3]=Student(4,60);
    student[4]=Student(5,90);
    Student *stu = &student[0];
    max(stu);
    return 0;
}