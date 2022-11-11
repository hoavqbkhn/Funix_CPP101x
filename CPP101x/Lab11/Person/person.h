#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;
class Person
{
public:
    Person();

    const string &getFirst_name() const;
    void setFirst_name(const string &newFirst_name);
    const string &getLast_name() const;
    void setLast_name(const string &newLast_name);
    int getAge() const;
    void setAge(int newAge);
    const string &getRace() const;
    void setRace(const string &newRace);
    const string &getPhone() const;
    void setPhone(const string &newPhone);

    virtual void outputIdentity() = 0;
    virtual void outputAge();

    string first_name;
    string last_name;

protected:
    string phone;
private:

    int age;
    string race;



};

#endif // PERSON_H
