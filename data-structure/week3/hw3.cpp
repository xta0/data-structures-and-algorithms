#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, int> symbols; 


bool remove_space(char c){
    if(c==' '){
        return false;
    }else{
        return true;
    }
}

string infix_to_postfix(string expr){
    stack<char> ss;
    string result;
    for(auto c : expr){
        switch(c){
            case '+':
            case '-':
            case '*': {
                int p = symbols[c];
                while(ss.top()){
                    char x = ss.top();
                    if(symbols.find(x)!=symbols.end()){
                        int q = symbols[x];
                        if(q>=x){
                            result += string(1,c);
                            ss.pop();
                        }else{
                            break;
                        }
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
                while(ss.top() != '('){
                    char x = ss.top();
                    ss.pop();
                    result += string(1,x);
                }
                ss.pop(); //pop'('
            };
            default:{
                result += string(1,c);
            }
        }
    }

    return result;
}

int main(){
    symbols.insert(make_pair('(',100));
    symbols.insert(make_pair('*',10));
    symbols.insert(make_pair('+',1));
    symbols.insert(make_pair('-',1));
    
    int n;
    cin >> n;
    cin.ignore();
    int count = 2;
    string r1,expr1;
    string r2,expr2;
    for(int i=0;i<n;++i){
        while(count > 0){
            std::getline(cin,r1);
            std::copy_if(r1.begin(),r1.end(),expr1.begin(), remove_space);            
            expr1 = infix_to_postfix(expr1);
            std::getline(cin,r2);
            std::copy_if(r2.begin(),r2.end(),expr2.begin(), remove_space);
            expr2 = infix_to_postfix(expr2);            
            count--;
        }
    }
    return 0;
}