#ifndef STUDENT_H
#define STUDENT_H
#include <string>


using namespace std;
class Student
{
public:
    Student();
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

    void sitInClass();
private:
    string first_name;
    string last_name;
    int age;
    string address;
    string city;
    string phone;
};

#endif // STUDENT_H
