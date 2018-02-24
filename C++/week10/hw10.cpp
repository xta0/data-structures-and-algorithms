#include <iostream>
#include <map>
using namespace std;
// 在此处补充你的代码
class A{
public:
    int x;
    static int count;
    A(){x = 0; ++count;}
    A(int _x){
        ++count;
        x = _x;
    }
    A(const A& a){
        ++count;
    }
    virtual ~A(){
        cout<<"A::destructor"<<endl;
        --count;
    }
};
class B:public A{
public: 
    B(int _x):A(_x){};
    B(const B& b):A(b){};
    virtual ~B(){
       cout<<"B::destructor"<<endl;
    }
};
int A::count = 0;
void func(B b) { }
int main()
{
        A a1(5),a2;
        cout << A::count << endl;
        B b1(4);
        cout << A::count << endl;
        func(b1);
        cout << A::count << endl;
        A * pa = new B(4);
        cout << A::count << endl;
        delete pa;
        cout << A::count << endl;
        return 0;
}