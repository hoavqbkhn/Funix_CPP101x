#ifndef PARENTCLASS_H
#define PARENTCLASS_H
#include <iostream>

class ParentClass
{
public:
    ParentClass();
    virtual void say(){
        std::cout << "papa" << std::endl;
    }
};

#endif // PARENTCLASS_H
