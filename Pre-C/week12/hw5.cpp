#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){

    char substr[10];
    char str[10];

    cin >> substr;
    cin.get();

    cin>> str;
    cin.get();

    int l1 = strlen(substr);
    int l2 = strlen(str);

    int max_pos=0;
    int max_ascii=0;
    for(int i=0;i<l1;i++){
        if(substr[i] > max_ascii){
            max_ascii = substr[i];
            max_pos=i;
        }
    }
    for(int i=0; i<l1; i ++){
        
        if(i>max_pos){
            substr[i+l2] = substr[i];
            substr[i]=0;
        }
    }
    for(int j=0; j<l2;j++){
        substr[max_pos+j+1]=str[j];
    }
    
    for(int i=0;i<l1+l2;i++){
        cout<<substr[i];
    }

    return 0;
}