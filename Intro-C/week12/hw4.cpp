#include <iostream>

using namespace std;
int main(){
    int op1=0,op2=0;
    char op;
    cin >> op1 >> op2 >> op;
    int result = 0;
    switch(op){
        case '+':{
            result = op1+op2;
            break;
        }
        case '-':{
            result = op1-op2;
            break;
        }
        case '*':{
            result = op1 * op2;
            break;
        }
        case '/':{
            if(op2 == 0){
                cout <<"Divided by zero!";
                return 0;
            }
            result = op1/op2;
            break;
        }
        default:{
            cout <<"Invalid operator!";
            return 0;
        }
    }
    cout <<result;

    return 0;
}