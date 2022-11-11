#ifndef COURSE_H
#define COURSE_H
#include "student.h"
#include "teacher.h"
class Course
{
public:
    Course();
    ~Course();

    const string &getName() const;
    void setName(const string &newName);

    const Teacher &teacher() const;
    void setTeacher(const Teacher &newTeacher);

    void addStudent(Student std);

private:
   Student mStudents[3];
   Teacher mTeacher;
   int i = 0;

   string name{"Intermediate C++"};

};

#endif // COURSE_H
