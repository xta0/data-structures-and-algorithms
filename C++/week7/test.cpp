#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class MyException: public exception{
public:
     virtual const char* what() const throw(){// const throw 意思是这个函数不会抛出异常
        return "MyExcepiton!";
     }
};

void throwException() throw(){
    throw MyException();
}

int main()
{
    try{
        throwException();
    }catch(MyException &e){
        cout<<e.what()<<endl;
    }
}