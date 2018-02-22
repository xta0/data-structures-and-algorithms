#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;
int main(){
    
    int n;
    cin>>n;
    map<int,int> m;
    m[1]=1000000000;
    for(int i=0;i<n;++i){
        int index,p;
        cin>>index>>p;
        m[index]=p;
    }    
    map<int,int>::iterator it = m.begin();
    for(;it!=m.end();++it){
        int key = it->first;
        int value = it->second;
        int min_key = 0;
        int min_value = 0;
        int min=1000000000;
        for(int i=1;i<key;i++){
            int val = m[i];
            int sub = abs(value-val);
            if(sub<min){
                min=sub;
                min_key = i;
                min_value=val;
            }else if(sub == min){
                if(val<min_value){
                    min_key=i;
                    min_value = val;
                }
            }
        }
        if(key>1){
            cout<<key<<" "<<min_key<<endl;
        }
        
    }
    
    
    
    return 0;
}
