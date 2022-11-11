#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class Student: public Person
{
public:
    Student();
    void outputIdentity() override;
    void outputAge() override;
};

#endif // STUDENT_H
