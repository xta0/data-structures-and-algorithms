#include <string>
#include <iostream>
using namespace std;

class A{
public: 
    virtual void vfunc(){
        cout<<"A.vfunc()"<<endl;
    }
    void func(){
        cout<<"A.func()"<<endl;
        this->vfunc(); 
    };
};
class B:public A{
public:     
    void func(){
        cout<<"B.func()"<<endl;
    };
    virtual void vfunc(){
        cout<<"B.vfunc()"<<endl;
    }
    void b(){
        cout<<"B.b()"<<endl;
    };
};

class Base{
public:
	int i;
	virtual void print(){ cout<<"Base:Print"; }
};
class Derived: public Base{
public:
	int n;
	virtual void print(){ cout<<"Derived:Print"<<endl; }
};

int main(){

    B b;
    A &r = b;
    A* p = &b;
    r.vfunc();
    p -> vfunc();
    p -> func();

    Derived d;
    size_t szint = sizeof(int);
	size_t sz1 = sizeof(Base);
	size_t sz2 = sizeof(Derived);
    cout<<"Size:Int:"<<szint<<endl;
    cout<<"Size:Base:"<<sz1<<endl;
    cout<<"Size:Derived:"<<sz2<<endl;
    return 0;
}