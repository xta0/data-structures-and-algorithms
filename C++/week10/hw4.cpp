#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType{
public:
    int x;
    CType(){
        x = 0;
    }
    CType(const CType& type){
        x = type.x;
    }
    void setvalue(int n){
        x = n;
    }
    CType operator++(int){
        CType tmp(*this);
        x = x*x;
        return tmp;
    }
    operator int(){
        return x;
    }
    
};

int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}