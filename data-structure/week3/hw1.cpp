#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string str("");
    string res("");
    while(n > 0){
        std::getline(cin, str);
        for(int i=0;i<str.length();++i){
            char c = str[i];
            if(isalpha(c)){
                if( c != 'z' && c!= 'Z' ){
                    c+=1;
                }else{
                    c-=25;
                }
            }
            res+=c;
        }
        cout<<res<<endl;
        str = "";
        res = "";
        n--;
    }
    return 0;
}
