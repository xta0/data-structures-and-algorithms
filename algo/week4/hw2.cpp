#include <iostream>
using namespace std;


bool dead(int* p, int i, int j, int r, int c){
    if(i>=r || j>=c){
        return false;
    }
    if(p[i][j])
}
void find(){

}

int main(){

    int R,C;
    cin >>R>>C;
    int a[R][C];

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cin >> a[i][j];
        }
    }

    

    return 0;
}