#include <iostream>
using namespace std;

/*
输出
destructor B
destructor A
*/
class A {
// 在此处补充你的代码
public: 
    virtual ~A(){ cout<<"destructor A"<<endl; }
};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}