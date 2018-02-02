#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

class Hello
{
    private:
        int x;

	public:
        Hello(){}
        int getX() const{
            return this->x;
        }
		void print(){
            printf("hello!\n");
        };
};

class B{

public:
    B(int x){
        val = x;
    }
    static void printVal();
    static int val;
};

int B::val = 0;

void B::printVal(){
    cout<<__FUNCTION__<<"L "<<B::val<<endl;
}

int main(){
    
    string s = "a";
    B b(10);
    B::printVal();
    b.printVal();

    cout<<"typeid(s): "<<typeid(s).name()<<endl;
    cout<<"typeid(B): "<<typeid(B).name()<<endl;

    Hello* p = nullptr;
	p -> print();

    cout<<"typeid(p): "<<typeid(p).name()<<endl;

    const Hello hello;
    cout<<"typeid(hello): "<<typeid(hello).name()<<endl;
    int x = hello.getX();
    cout<<"typeid(x): "<<typeid(x).name()<<endl;
    // hello.x = 100;
    // hello.print();


    return 0;
}