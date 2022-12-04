#ifndef CHILDRENCLASS_H
#define CHILDRENCLASS_H

#include "parentclass.h"
class ChildrenClass : public ParentClass
{
public:
    ChildrenClass();
    void say(){
        std::cout << "Child" << std::endl;
    }
};

#endif // CHILDRENCLASS_H
