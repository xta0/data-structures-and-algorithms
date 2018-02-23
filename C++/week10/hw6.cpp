#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
// 在此处补充你的代码
class MyString{
public:
    string s;
    MyString(){
        s= "";
    }
    MyString(const char* str){
        s = string(str);
    }
    MyString(const MyString& str){
        s = str.s;
    }
    MyString& operator=(const char* str){
        s = string(str);
        return *this;
    }
    MyString& operator+=(const char* str){
        // MyString tmp;
        s = s + string(str);
        return *this;
    }
    string operator()(int index, int len){
        return s.substr(index,len);
    }
    char& operator[](int index){
        return s[index];
    }
    operator char*(){
        return (char* )s.c_str();
    }
    friend const char* operator+(const char* str, const MyString& mstr){
        string s1(str);
        string s2 = mstr.s;
        string s = s1+s2;
        return s.c_str();
    }
    friend MyString operator+(const MyString& str1, const MyString& str2){
        MyString tmp;
        tmp.s = str1.s+str2.s;
        return tmp;
    }
    bool operator<(const MyString& str){
        return s<str.s;
    }
    bool operator>(const MyString& str){
        return s>str.s;
    }
      bool operator==(const MyString& str){
        return s==str.s;
    }

};
int CompareString( const void * e1, const void * e2)
{
        MyString * s1 = (MyString * ) e1;
        MyString * s2 = (MyString * ) e2;
        if( * s1 < *s2 )
                 return -1;
        else if( *s1 == *s2)
                 return 0;
        else if( *s1 > *s2 )
                 return 1;
}
/*
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
*/
int main()
{
        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
        MyString SArray[4] = {"big","me","about","take"};
        cout << "1. " << s1 << s2 << s3<< s4<< endl;
        s4 = s3;
        s3 = s1 + s3;
        cout << "2. " << s1 << endl;
        cout << "3. " << s2 << endl;
        cout << "4. " << s3 << endl;
        cout << "5. " << s4 << endl;
        cout << "6. " << s1[2] << endl;
        s2 = s1;
        s1 = "ijkl-";
        s1[2] = 'A' ;
        cout << "7. " << s2 << endl;
        cout << "8. " << s1 << endl;
        s1 += "mnop";
        cout << "9. " << s1 << endl;
        s4 = "qrst-" + s2;
        cout << "10. " << s4 << endl;
        s1 = s2 + s4 + " uvw " + "xyz";
        cout << "11. " << s1 << endl;
        qsort(SArray,4,sizeof(MyString),CompareString);
        for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
        //s1的从下标0开始长度为4的子串
        cout << s1(0,4) << endl;
        //s1的从下标5开始长度为10的子串
        cout << s1(5,10) << endl;
        return 0;
}