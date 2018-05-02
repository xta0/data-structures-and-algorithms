#include <queue>
#include <cstdio>
using namespace std;

int main(){
    priority_queue<int,std::vector<int>, greater<int>> qq;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int type;
        scanf("%d",&type);
        if(type == 1){
            int num;
            scanf("%d",&num);
            qq.push(num);
        }else{
            printf("%d\n",qq.top());
            qq.pop();
        }
    }

    return 0;
}