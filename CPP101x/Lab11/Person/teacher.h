#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class Teacher : public Person
{
public:
    Teacher();
    void outputIdentity() override;
    void outputAge() override;
};

#endif // TEACHER_H
