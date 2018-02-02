#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// 姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

// 其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

// 各部分内容之间均用单个英文逗号","隔开，无多余空格。

// 输出
// 一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。


class Student{
public:
    Student(string name="", 
    unsigned short age=0,
    string id="",
    unsigned short score1=0,
    unsigned short score2=0,
    unsigned short score3=0,
    unsigned short score4=0 )
    :name(name),
    age(age),
    id(id),
    score1(score1),
    score2(score2),
    score3(score3),
    score4(score4){}

string getName(){
    return this->name;
}
string getId(){
    return this->id;
}
unsigned short getAge(){
    return this->age ;
}
unsigned short getAvgGrade(){
    return (this->score1+this->score2+this->score3+this->score4)/4;
}

private:
    string name;
    unsigned short age;
    string id;
    unsigned short score1;
    unsigned short score2;
    unsigned short score3;
    unsigned short score4;
};


int main(){


    

    // char input[1000];
    // cin>>input;

    // char* n=strtok(input,",");
    // string name(n); y

    // char* a = strtok(NULL,",");
    // int age = 0;
    // if(a){
    //     age=atoi(a);
    // }
    // string id="";
    // char* i=strtok(NULL,",");
    // if(i){
    //     id=string(i);
    // }
    // int grade1=0,grade2=0,grade3=0,grade4=0;
    // char* g1=strtok(NULL,",");
    // if(g1){
    //     grade1 = atoi(g1);
    // }
    // char* g2=strtok(NULL,",");
    //   if(g2){
    //     grade2 = atoi(g2);
    // }
    // char* g3=strtok(NULL,",");
    //   if(g3){
    //     grade3 = atoi(g3);
    // }
    // char* g4=strtok(NULL,",");
    //   if(g4){
    //     grade4 = atoi(g4);
    // }

    // Student st(name,age,id,grade1,grade2,grade3,grade4);

    // cout<<st.getName()<<","
    // <<st.getAge()<<","
    // <<st.getId()<<","
    // <<st.getAvgGrade();

    return 0;
}