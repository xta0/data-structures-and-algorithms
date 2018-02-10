#include <string>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

/*
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over
 */

/*
 Op29adfk48
 358
 329strjvc
 Op29adfk48
 35a8
 */

string toString(int num){
    stringstream ss;
    ss << num;
    return ss.str();
}

int  toNumber(string str){
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

vector<string> strings;
queue<string> tokens;
/*
 copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
 */
string copy(string arg1, string arg2, string arg3){
    string substr="";
    int n = toNumber(arg1)-1;
    int l = toNumber(arg3);
    string s = strings[n];
    int x = toNumber(arg2);
    if(x != string::npos){
        substr = s.substr(x,l);
        //        cout<<__func__<<": find substring: "<<substr<<endl;
        
    }else{
        //        cout<<__func__<<": can't find character: "<<arg2<<endl;
    }
    return substr;
}
bool is_number(const string& s)
{
    for(int i=0;i<s.length();++i){
        char c = s[i];
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}
/*
 * add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
 */
string add (string arg1, string arg2){
    
    string ret="";
    if(is_number(arg1) && is_number(arg2)){
        int a1 = toNumber(arg1);
        int a2 = toNumber(arg2);
        if((a1>0&&a1<99999) && (a2>0&&a2<99999)){
            int r = a1+a2;
            ret = toString(r);
            
        }else{
            ret = arg1+arg2;
        }
    }else{
        return arg1+arg2;
    }
    
    //    cout<<__func__<<": return string: "<<ret<<endl;
    return ret;
}
/*
 find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
 */
string find(string arg1, string arg2 ){
    size_t ret = 0 ;
    int n = toNumber(arg2)-1;
    string x = strings[n];
    ret = x.find_first_of(arg1);
    if(ret != string::npos){
        //        cout<<__func__<<": found sub string: "<<arg1<<" in: "<<x<<" at: "<<ret<<endl;
        return toString(ret);
    }else{
        //        cout<<__func__<<": can't find sub string: "<<arg1<<" return length: "<<ret<<endl;
        return toString(x.size());
    }
}

/*
 rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
 */
string rfind(string arg1, string arg2){
    size_t ret = 0;
    int n = toNumber(arg2)-1;
    string x = strings[n];
    ret = x.find_last_of(arg1);
    if(ret != string::npos){
        //        cout<<__func__<<": found sub string: "<<arg1<<" in: "<<x<<" at: "<<ret<<endl;
        return toString(ret);
    }else{
        //        cout<<__func__<<": can't find sub string: "<<arg1<<" return length: "<<ret<<endl;
        return toString(x.size());
    }
}

//insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
string insert(string arg1, string arg2 , string arg3){
    
    int n = toNumber(arg2)-1;
    int x = toNumber(arg3);
    string &t = strings[n];
    t.insert(x,arg1);
    return "";
}

//reset S N：将第N个字符串变为S。
string  reset (string arg1, string arg2){
    // int i = 0;
    int n = toNumber(arg2)-1;
    int index = -1;
    for(int i=0;i<strings.size();++i){
        if(i==n){
            index=i;
            break;
        }
    }
    if(index != -1){
        strings[index] = arg1;
    }
    return "";
}

//print N：打印输出第N个字符串。
string print(string arg1){
    int n = toNumber(arg1)-1;
    cout << strings[n]<<endl;
    return "";
}
//printall：打印输出所有字符串。
string printall(){
    for(int i=0;i<strings.size();++i){
        cout<<strings[i]<<endl;
    }
    return "";
}

inline bool isCompoundToken(string token){
    if( token=="copy"||
       token=="insert"||
       token=="find" ||
       token=="rfind"||
       token=="add"||
       token=="print" ||
       token=="printall"){
        return true;
    }
    else{
        return  false;
    }
}
inline int numberOfArguments(string token){
    if( token=="copy" || token == "insert"){
        return 3;
    }else if(token == "find" || token == "rfind" || token == "add" || token == "reset"){
        return 2;
    }else if(token == "print"){
        return 1;
    }else if(token == "printall"){
        return 0;
    }else{
        return -1;
    }
}

class Node{
    bool compound;
    string content;
    int args;
public:
    vector<Node* > children;
    // Node(){
    //     compound=false;
    //     content="";
    // }
    Node(string token){
        content = token;
        compound = isCompoundToken(token);
        args = numberOfArguments(token);
    }
    string getContent() const{
        return content;
    }
    bool isCompound() const{
        return compound;
    }
    bool hasChildren() const{
        return children.size() > 0;
    }
    int numOfArgs() const{
        return args;
    }
    
    void log(){
        cout<<"["<<content<<"]"<<endl;
        for(int i=0;i<children.size();++i){
            Node* node = children[i];
            if(node->isCompound()){
                node->log();
            }else{
                cout<<node->content<<endl;
            }
        }
    }
    string calculate(){
        vector<string> tmp(0);
        for(int i=0;i<children.size();++i){
            Node* node = children[i];
            if(node->compound){
                string arg = node->calculate();
                tmp.push_back(arg);
            }else{
                tmp.push_back(node->content);
            }
        }
        if(content == "copy"){
            return copy(tmp[0],tmp[1],tmp[2]);
        }else if(content == "add"){
            return add(tmp[0],tmp[1]);
        }else if(content == "find"){
            return find(tmp[0],tmp[1]);
        }else if(content == "rfind"){
            return rfind(tmp[0],tmp[1]);
        }else if(content == "insert"){
            return insert(tmp[0],tmp[1],tmp[2]);
        }else if(content == "reset"){
            return reset(tmp[0],tmp[1]);
        }else if(content == "print"){
            return print(tmp[0]);
        }else if(content == "printall"){
            return printall();
        }
        else{
            return content;
        }
    }
};

void tree(Node* root){
    for(int i=0; i<root->numOfArgs(); ++i){
        string token = tokens.front();
        tokens.pop();
        Node *node = new Node(token);
        root->children.push_back(node);
        if(node->isCompound()){
            tree(node);
        }
    }
}


int main(){
    int n=0;
    cin >> n;
    for(int i=0;i<n;++i){
        string tmp;
        cin >> tmp;
        strings.push_back(tmp);
    }
    
    string expression;
    
    while(getline(cin, expression)){
        if(expression == "over"){
            break;
        }
        if(expression.length() == 0){
            continue;
        }
        char* buffer = (char* )expression.c_str();
        char *token = strtok(buffer, " ");
        Node* root = new Node(string(token));
        while (token)
        {
            tokens.push(string(token));
            token = strtok(NULL, " ");
        }
        //create a tree
        tokens.pop();
        tree(root);
        //        root->log();
        root->calculate();
    }
    
    return 0;
}

