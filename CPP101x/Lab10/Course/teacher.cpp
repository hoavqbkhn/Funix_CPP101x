#include "teacher.h"

Teacher::Teacher()
{

}

const string &Teacher::getFirst_name() const
{
    return first_name;
}

void Teacher::setFirst_name(const string &newFirst_name)
{
    first_name = newFirst_name;
}

const string &Teacher::getLast_name() const
{
    return last_name;
}

void Teacher::setLast_name(const string &newLast_name)
{
    last_name = newLast_name;
}

int Teacher::getAge() const
{
    return age;
}

void Teacher::setAge(int newAge)
{
    age = newAge;
}

const string &Teacher::getAddress() const
{
    return address;
}

void Teacher::setAddress(const string &newAddress)
{
    address = newAddress;
}

const string &Teacher::getCity() const
{
    return city;
}

void Teacher::setCity(const string &newCity)
{
    city = newCity;
}

const string &Teacher::getPhone() const
{
    return phone;
}

void Teacher::setPhone(const string &newPhone)
{
    phone = newPhone;
}

void Teacher::gradeStudent()
{
    printf("Student graded\n");
}

void Teacher::sitInClass()
{
    printf("Sitting at front of class\n");
}
