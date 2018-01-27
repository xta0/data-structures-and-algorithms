#include <iostream>
using namespace std;

typedef struct {
    char id[3];
    double score;
}Patient;

int main(){

    int m=0;
    double  a=0;
    cin>>m>>a;

    Patient list[51];
    for(int i=0;i<m;i++){
        Patient p;
        cin>>p.id>>p.score;
        list[i] = p;
    }
   
   Patient tmp = {0,0};
   for(int i=0;i<m-1;i++){
       for(int j=0; j<m-1-i;j++){
           Patient p1 = list[j];
           Patient p2 = list[j+1];
           if(p1.score < p2.score){
               tmp = list[j];
               list[j]  = list[j+1];
               list[j+1]  = tmp;
           }
       }
   }

   bool b=false;
   for(int i=0;i<m;i++){
       Patient p = list[i];
       if(p.score > a){
           printf("%s %.1f\n",p.id,p.score );
           b = true;
       }
   }
   if(!b){
       cout<<"none";
   }
    



    return 0;
}