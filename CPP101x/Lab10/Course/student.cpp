#include "student.h"

Student::Student()
{

}

const string &Student::getFirst_name() const
{
    return first_name;
}

void Student::setFirst_name(const string &newFirst_name)
{
    first_name = newFirst_name;
}

const string &Student::getLast_name() const
{
    return last_name;
}

void Student::setLast_name(const string &newLast_name)
{
    last_name = newLast_name;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

const string &Student::getAddress() const
{
    return address;
}

void Student::setAddress(const string &newAddress)
{
    address = newAddress;
}

const string &Student::getCity() const
{
    return city;
}

void Student::setCity(const string &newCity)
{
    city = newCity;
}

const string &Student::getPhone() const
{
    return phone;
}

void Student::setPhone(const string &newPhone)
{
    phone = newPhone;
}

void Student::sitInClass()
{
    printf("Sitting in main theater\n");
}
