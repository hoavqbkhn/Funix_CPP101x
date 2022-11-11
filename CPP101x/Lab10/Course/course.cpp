#include "course.h"

Course::Course()
{

}

Course::~Course()
{

}

const string &Course::getName() const
{
    return name;
}

void Course::setName(const string &newName)
{
    name = newName;
}

const Teacher &Course::teacher() const
{
    return mTeacher;
}

void Course::setTeacher(const Teacher &newTeacher)
{
    mTeacher = newTeacher;
}

void Course::addStudent(Student std)
{
    if(i!= 3){
       mStudents[i++] = std;
    }
}
