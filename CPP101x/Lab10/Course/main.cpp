#include <iostream>
#include "course.h"
using namespace std;

int main()
{
    Student std1;
    std1.setFirst_name("hoavq1");
    Student std2;
    std1.setFirst_name("hoavq2");
    Student std3;
    std1.setFirst_name("hoavq3");

    Teacher tch;
    tch.setFirst_name("hoavq0");
    Course crs;
    crs.setTeacher(tch);
    crs.addStudent(std1);
    crs.addStudent(std2);
    crs.addStudent(std3);

    crs.setName("Intermediate C++");
    cout << crs.getName() << endl;
    tch.gradeStudent();

    return 0;
}
