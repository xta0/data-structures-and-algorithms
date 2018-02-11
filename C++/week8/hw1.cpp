#include <iostream> 
#include <iterator> 
#include <set> 
#include <list>
using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
// 在此处补充你的代码     
    int sz = sizeof(a)/sizeof(int);
    set<int> v(a,a+sz); 
    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 

    list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);



    return 0;
}