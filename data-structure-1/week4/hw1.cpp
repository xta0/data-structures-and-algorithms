#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map<string, int> dictionary;

void init(){
    dictionary["zero"] = 0;
    dictionary["one"] = 1;
    dictionary["two"] = 2;
    dictionary["three"] = 3;
    dictionary["four"] = 4;
    dictionary["five"] = 5;
    dictionary["six"] = 6;
    dictionary["seven"] = 7;
    dictionary["eight"] = 8;
    dictionary["nine"] = 9;
    dictionary["ten"] = 10;
    dictionary["eleven"] = 11;
    dictionary["twelve"] = 12;
    dictionary["thirteen"] = 13;
    dictionary["fourteen"] = 14;
    dictionary["fifteen"] = 15;
    dictionary["sixteen"] = 16;
    dictionary["seventeen"] = 17;
    dictionary["eighteen"] = 18;
    dictionary["nineteen"] = 19;
    dictionary["twenty"] = 20;
    dictionary["thirty"] = 30;
    dictionary["forty"] = 40;
    dictionary["fifty"] = 50;
    dictionary["sixty"] = 60;
    dictionary["seventy"] = 70;
    dictionary["eighty"] = 80;
    dictionary["ninety"] = 90;
    dictionary["hundred"] = 100;
    dictionary["thousand"] = 1000;
    dictionary["million"] = 1000000;
}
int recursive(queue<string>& ss){
    int result = 0;
    int x = 0;
    while(!ss.empty()){
        string op1 = ss.front();
        if(op1 == "hundred"){
            x *= 100;
        }else if(op1 == "thousand"){
            x *= 1000;
            result += x;
            x = 0;
        }else if(op1 == "million"){
            x *= 1000000;
            result += x;
            x = 0;
        }else{
            map<string,int>::const_iterator itor = dictionary.find(op1);
            x += itor->second;
        }
        ss.pop();
    }
    result += x;
    return result;
}

/*
six
negative seven hundred twenty nine
one thousand five hundred
fourteen thousand eleven hundred
one million one hundred one
eight hundred fourteen thousand twenty two
eight thousand fourteen hundred twenty two
 */
int main(){
    init();
    string str;
    queue<string> ss;
    while(std::getline(cin, str) && str.length()!=0){
        char* buff = (char* )str.c_str();
        char* token = strtok(buff," ");
        while(token){
            ss.push(string(token));
            token = strtok(NULL," ");
        }
        bool neg = false;
        if(ss.front() == "negative"){
            neg = true;
            ss.pop();
        }
        long long sum = recursive(ss);
        if(neg){
            sum *= -1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
