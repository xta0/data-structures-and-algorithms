#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
int *psum = NULL;
void func(int x){
    if(x == 1){
        *psum += 1;
        return;
    }
    else if(x == 0){
        return;
    }
    else{
        int b = -1;
        for(int i=0;i<3;++i){
            b = x%2;
            if(i==0){
                b=1*b;
            }else if(i==1){
                b=2*b;
            }else{
                b =4*b;
            }
            *psum += b;
            x = x/2;
        }
    }
}

typedef void(*fptr)(int);
fptr CMy_add(int& sum){
    psum = &sum;
    return func;
};

int main(int argc, char* argv[]) {
    int v, my_sum=0;
    vector<int> vec;
    cin>>v;
    while ( v ) {
        vec.push_back(v);
        cin>>v;
    }
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));
    cout<<my_sum<<endl;
    return 0;
}
