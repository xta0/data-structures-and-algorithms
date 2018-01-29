#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){

    char line[101];
    cin.getline(line,100);

    int op1 = atoi(strtok(line,","));
    int op2 = atoi(strtok(NULL,","));
    int r =  atoi(strtok(NULL,","));

    if(op1+op2 == r){
        cout<<"+"<<endl;
    }else if(op1*op2 == r){
        cout<<"*"<<endl;       
    }else if(op1-op2 == r){
        cout<<"-"<<endl;
    }else if(op1/op2 == r){
        cout<<"/"<<endl;
    }else if(op1%op2 == r){
        cout<<"%"<<endl;
    }else{
        cout<<"error";
    }
    return 0;
}