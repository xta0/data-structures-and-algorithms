#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
    int r;
    bool b;
}RET;

char output[101];
int x=0;
RET find(char* str, int l){
    
    char c = str[l];
    if(c=='\0'){
        return {l,false};
    }
    if(c == '('){
        x++;
        RET result = find(str, l+1);
        if(result.b == true){
            x--;
            return find(str,result.r+1);
        }else{
            output[l]='$';
            return{l,false};
        }
        
    }else if(c==')'){
        if(x <= 0){
            output[l]='?';
            return find(str,l+1);
        }else{
            return {l,true};
        }
    }else{
        return find(str,l+1);
    }
}

int main(){
    
    char input[101];
    while(cin.getline(input,101)){
        
        cout<<input<<endl;
        for(int i=0;i<100;i++){
            output[i]=' ';
        }
        find(input,0);
        int len = (int)strlen(input);
        for(int i=0;i<len;i++){
            cout<<output[i];
        }
        cout<<endl;
        x=0;
    };

    return 0;
}

