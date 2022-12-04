#ifndef CHIDRENCLASS2_H
#define CHIDRENCLASS2_H
#include "parentclass.h"

class ChildrenClass2 : public ParentClass
{
public:
    ChildrenClass2();
    void say(){
        std::cout << "child2" << std::endl;
    }
};

#endif // CHIDRENCLASS2_H
