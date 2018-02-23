#include <iostream>
using namespace std;

/*
2
2
8
10
*/
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
    Number(const Number& m){
        num = m.num;
    }
    int& value(){
        return num;
    }
    void operator+(const Number& m){
        num = num + m.num;
    }
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}