#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
    int r;
    bool b;
}RET;

char output[100];
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
    
    char input[100]={0};
    cin.getline(input,100);
    cout << input <<endl;
    find(input,0);
    
    for(int i=0;i<strlen(input);i++){
        char c = output[i];
        if(c!='$' && c!='?'){
            cout<<" ";
        }else{
            cout<<c;
        }
    }
    cout<<endl;
    
    return 0;
}
