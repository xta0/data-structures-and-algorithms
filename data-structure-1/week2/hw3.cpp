#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

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

string add(string s1, string s2){
    int n = (int)max(s1.size(), s2.size());
    if (n > s1.size()){
        s1 = string(n-s1.size(), '0') + s1;
    }
    if (n > s2.size()){
        s2 = string(n-s2.size(), '0') + s2;
    }
    string result(n+1, '0');
    bool carry = false;
    for(int i = n-1; i>=0; i--){
        int c1 = s1[i] - '0';
        int c2 = s2[i] - '0';
        int x = c1+c2;
        if(carry){
            x += 1;
        }
        if(x > 9){
            x -= 10;
            carry = true;
        }else{
            carry = false;
        }
        char z = x + '0';
        result[i+1] = z;
    }
    result[0] = carry?'1':'0';
    n = (int)result.find_first_not_of('0');
    if(n!=string::npos){
        result = result.substr(n);
    }
    return result;
};

string rectStrMult(string s1, string s2, int sz){
    if(sz <= 2){
        int op1 = toNumber(s1);
        int op2 = toNumber(s2);
        int temp = op1*op2;
        return toString(temp);
        
    }else{
        
        sz = (int)max(s1.length(), s2.length());
        if(sz%2==1){
            sz+=1;
        }
        s1 = string(sz-s1.length(),'0')+s1;
        s2 = string(sz-s2.length(),'0')+s2;
        //split s1 to a,b
        string a = s1.substr(0,sz/2);
        string b = s1.substr(sz/2,s1.length());
        //split s2 to c,d
        string c = s2.substr(0,sz/2);
        string d = s2.substr(sz/2,s2.length());
        
        string ac = rectStrMult(a,c,sz/2);
        string ad = rectStrMult(a,d,sz/2);
        string bc = rectStrMult(b,c,sz/2);
        string bd = rectStrMult(b,d,sz/2);
        
        ac = ac + string(sz,'0');
        string adbc = add(ad,bc) + string(sz/2,'0');
        
        string result = add(add(ac, adbc),bd);
        return result;
    }
 
}

int main(){
    string s1; string s2;
    cin>>s1>>s2;
    string r = rectStrMult(s1,s2,(int)max(s1.length(), s2.length()));
    cout<<r<<endl;
    return 0;
}
