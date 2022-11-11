#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "student.h"
using namespace std;
class Teacher
{
public:
    Teacher();

    const string &getFirst_name() const;
    void setFirst_name(const string &newFirst_name);
    const string &getLast_name() const;
    void setLast_name(const string &newLast_name);
    int getAge() const;
    void setAge(int newAge);
    const string &getAddress() const;
    void setAddress(const string &newAddress);
    const string &getCity() const;
    void setCity(const string &newCity);
    const string &getPhone() const;
    void setPhone(const string &newPhone);

    void gradeStudent();
    void sitInClass();
private:
    string first_name;
    string last_name;
    int age;
    string address;
    string city;
    string phone;
};

#endif // TEACHER_H
