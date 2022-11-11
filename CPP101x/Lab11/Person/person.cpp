#include "person.h"

Person::Person()
{

}

const string &Person::getFirst_name() const
{
    return first_name;
}

void Person::setFirst_name(const string &newFirst_name)
{
    first_name = newFirst_name;
}

const string &Person::getLast_name() const
{
    return last_name;
}

void Person::setLast_name(const string &newLast_name)
{
    last_name = newLast_name;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int newAge)
{
    age = newAge;
}

const string &Person::getRace() const
{
    return race;
}

void Person::setRace(const string &newRace)
{
    race = newRace;
}

const string &Person::getPhone() const
{
    return phone;
}

void Person::setPhone(const string &newPhone)
{
    phone = newPhone;
}

void Person::outputAge()
{
    printf("I am %d years old", age);
}
