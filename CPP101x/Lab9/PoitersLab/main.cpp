#include <iostream>
#include <string>
using namespace std;


void passByValue(int val)
{
    val = 10;
}


void passByRef(int *val){
    cout << "passByRef" << endl;
    *val = 50;
}

class Person{

public:
    const string &getName() const;
    void setName(const string &newName);

    int getAge() const;
    void setAge(int newAge);

    int getHeight() const;
    void setHeight(int newHeight);

    int getWeight() const;
    void setWeight(int newWeight);

private:
    string name{"hoavq0"};
    int age;
    int height;
    int weight;
};


void modifyPerson(Person& person){
    cout << "modifyPerson" << endl;
    person.setName("hoavq1");
}

int main()
{
    int num1;
    int num2;
    int *pNum = &num2;
    num1 = 3;
    *pNum = 5;

    passByValue(num1);

    cout << num1 << endl;;

    passByRef(pNum);

    cout << *pNum << endl;

    double *pDouble = new double;
    *pDouble = 100.1;
    cout << *pDouble << endl;
    delete pDouble;
    cout << *pDouble << endl;

    Person p;
    cout << p.getName() << endl;
    modifyPerson(p);
    cout << p.getName() << endl;

    return 0;
}

const string &Person::getName() const
{
    return name;
}

void Person::setName(const string &newName)
{
    name = newName;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int newAge)
{
    age = newAge;
}

int Person::getHeight() const
{
    return height;
}

void Person::setHeight(int newHeight)
{
    height = newHeight;
}

int Person::getWeight() const
{
    return weight;
}

void Person::setWeight(int newWeight)
{
    weight = newWeight;
}
