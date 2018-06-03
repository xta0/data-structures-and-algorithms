#include<cstdio>  
#include<vector>  
using namespace std;  
vector<int> g[105];  
bool vis[105];  
int in[105],v,a,from,to;  
int main(){  
    scanf("%d%d",&v,&a);  
    while(a--){  
        scanf("%d%d",&from,&to);  
        g[from].push_back(to);  
        in[to]++;  
    }  
    int cnt = 0;  
    while(cnt < v){  
        for(int i =1;i<=v;i++){  
            if(in[i]==0&&!vis[i]){  
                printf("v%d ",i);  
                vis[i] = 1;  
                cnt++;  
                for(size_t j=0;j<g[i].size();j++){  
                    in[g[i][j]]--;  
                }  
                break;  
            }  
        }  
    }  
    printf("\n");  
    return 0;  
}  