#include <iostream>
using namespace std;

int map[8][8];
int visited[8];
int n = 0, m = 0, k = 0;
int total = 0;

void clear(int n){
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
}
void DFS(int row){
    if( k == m ){
        total++;
        return;
    }
    if(row >= n){
        return;
    }
    for(int i=0;i<n;i++){
        if(map[row][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            m++;
            DFS(row+1);
            visited[i]=0;
            m--;
        }
    }
    DFS(row+1);
}

/*
2 1
# .
. #
4 2
...#
..#.
.#..
#...
*/

int main()
{
    char ch;
    while (cin >> n >> k){
        if (n == -1 || k == -1){
            break;
        }
        m = 0;
        total = 0;
        clear(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> ch;
                if (ch == '#'){
                    map[i][j] = 1;
                }
                else{
                    map[i][j] = 0;
                }
            }
        }
        DFS(0);
        cout<<total<<endl;
    }
    
    return 0;
}
