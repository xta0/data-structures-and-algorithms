#include <iostream>
#include <string.h>
using namespace std;

char token;
int recursion(char* s,int l){
    int r  = 0;
    char c = s[l];
    if(c == token ){
        r  =recursion(s, l+1);
        cout<<l<<" "<<r<<endl;
        return recursion(s,r+1);
    }else{
        return l;
    }
}

int main(){
    char str[101] = {0};
    cin >> str;
    token = str[0];
    int r = recursion(str,1);
    cout << "0 " << r << endl;
    
    return 0;
    
}
