#include <iostream>
using namespace std;

int count = 0;
void dfs(int stack, int remain){
    if (remain == 0){
        ::count++;
        return;
    }
    if (stack == 0){
        dfs(stack+1, remain-1);
    }
    else{
        //pop
        dfs(stack-1 , remain);
        //push
        dfs(stack+1, remain - 1);
    }
}

int main(){
    int n;
    cin >> n;
    dfs(0, n);
    cout << ::count << endl;
    
    return 0;
}
