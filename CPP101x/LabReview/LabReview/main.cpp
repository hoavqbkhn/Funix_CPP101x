#include <iostream>
#include <string>

#include "childrenclass.h"
#include "ChidrenClass2.h"

using namespace std;


class MyException : public exception{
public:
    MyException(std::string ex){
        ex_ = ex;
    }
    char const* what() const{
        return ex_.c_str();
    }

private:
    std::string ex_;

};


void test(){
    throw MyException("hello");

}


int main()
{
    try{
        try{
            test();
        }catch(const exception& e){
            std::cout << e.what() << std::endl;
            throw e;
        }
    }catch(const MyException& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
