#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

map<char, int> symbols;

bool space(char c){
    if(c==' '){
        return true;
    }else{
        return false;
    }
}

string infix_to_postfix(string expr){
    stack<char> ss;
    string result;
    for(int i=0; i<expr.length(); ++i){
        char c = expr[i];
        switch(c){
            case '+':
            case '-':
            case '*': {
                int p = symbols[c];
                while(!ss.empty()){
                    char x = ss.top();
                    int q = symbols[x];
                    if(q>=p){
                        if(x == '('){
                            break;
                        }
                        ss.pop();
                        result += string(1,x);
                    }else{
                        break;
                    }
                }
                ss.push(c);
                break;
            };
            case '(':{
                ss.push(c);
                break;
            };
            case ')':{
                while(!ss.empty()){
                    char x = ss.top();
                    if(x != '('){
                        ss.pop();
                        result += string(1,x);
                    }else{
                        ss.pop(); //pop'('
                        break;
                    }
                }
                break;
            };
            default:{
                result += string(1,c);
                break;
            }
        }
    }
    while(!ss.empty()){
        result += string(1,ss.top());
        ss.pop();
    }
    
    return result;
}

int calculate_postfix(string expr){
    
    stack<int> ss;
    for(int i=0; i<expr.length(); ++i){
        char x = expr[i];
        switch(x){
            case '+':{
                int r = ss.top();
                ss.pop();
                int l = ss.top();
                ss.pop();
                int tmp(r+l);
                ss.push(tmp);
                break;
            }
            case '-':{
                int r = ss.top();
                ss.pop();
                int l = ss.top();
                ss.pop();
                int tmp(l-r);
                ss.push(tmp);
                break;
            }
            case '*': {
                int r = ss.top();
                ss.pop();
                int l = ss.top();
                ss.pop();
                int tmp(l*r);
                ss.push(tmp);
                break;
            }
            default:{
                if(isdigit(x)){
                    int tmp = x-'0';
                    ss.push(tmp);
                }else{
                    ss.push(x);
                }                
                break;
            }
        }
    }
    return ss.top();
}

int main(){
    
    symbols.insert(make_pair('(',100));
    symbols.insert(make_pair('*',10));
    symbols.insert(make_pair('+',1));
    symbols.insert(make_pair('-',1));
    
    int n;
    cin >> n;
    cin.ignore();
    string str1,expr1;
    string str2,expr2;
    for(int i=0;i<n;++i){
        std::getline(cin,str1);
        str1.erase(remove_if(str1.begin(), str1.end(), space),str1.end());
        expr1 = infix_to_postfix(str1);
        int result1 = calculate_postfix(expr1);
        std::getline(cin,str2);
        str2.erase(remove_if(str2.begin(), str2.end(), space),str2.end());
        expr2 = infix_to_postfix(str2);
        int result2 = calculate_postfix(expr2);
        if(result1 == result2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
