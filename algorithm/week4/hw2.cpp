#include <iostream>
using namespace std;


int a[100][100];
int cache[100][100];
int R=0 ,C = 0;

bool can_go_left(int r, int c){
    if(c-1 >= 0 && a[r][c-1] < a[r][c]){
        return true;
    }else{
        return false;
    }
}
bool can_go_right(int r, int c){
    if(c+1 < C && a[r][c+1] < a[r][c]){
        return true;
    }else{
        return false;
    }
}

bool can_go_top(int r, int c){
    if(r-1 >= 0 && a[r-1][c] < a[r][c]){
        return true;
    }else{
        return false;
    }
}

bool can_go_bottom(int r, int c){
    if(r+1 < R && a[r+1][c] < a[r][c]){
        return true;
    }else{
        return false;
    }
}
bool dead(int r, int c){
    if( !can_go_left(r,c) &&
       !can_go_right(r,c) &&
       !can_go_top(r,c) &&
       !can_go_bottom(r,c)){
        return true;
    }else{
        return false;
    }
}

int find(int x, int y){
    
    //    cout<<"find a["<<x<<"]["<<y<<"]"<<endl;
    int cl = 0, cr = 0, ct = 0, cb = 0;
    
    if(dead(x,y)){
        return 0;
    }
    
    if(can_go_left(x,y)){ //go left
        cl++;
        if(cache[x][y-1] != -1){
            //            cout<<"read cache a["<<x<<"]["<<y-1<<"] =>"<<cache[x][y-1]<<endl;
            cl += cache[x][y-1];
        }else{
            cl += find(x,y-1);
        }
        
    }
    if(can_go_right(x,y)){
        cr ++;
        if(cache[x][y+1] != -1){
            //            cout<<"read cache a["<<x<<"]["<<y+1<<"] =>"<<cache[x][y+1]<<endl;
            cr += cache[x][y+1];
        }else{
            cr += find(x,y+1);
        }
    }
    if(can_go_top(x,y)){
        ct ++;
        if(cache[x-1][y] != -1){
            //            cout<<"read cache a["<<x-1<<"]["<<y<<"] =>"<<cache[x-1][y]<<endl;
            ct += cache[x-1][y];
        }else{
            ct+=find(x-1,y);
        }
    }
    if(can_go_bottom(x,y)){
        cb++;
        if(cache[x+1][y] != -1){
            //            cout<<"read cache a["<<x+1<<"]["<<y<<"] =>"<<cache[x+1][y]<<endl;
            cb += cache[x+1][y];
        }else{
            cb += find(x+1,y);
        }
    }
//    int max_value = std::max({cl,cr,ct,cb});
    int max_value = std::max(std::max(std::max(cl,cr),ct),cb);
    cache[x][y] = max_value;
    //    cout<<"cache a["<<x<<"]["<<y<<"]=>"<<max_value<<endl;
    return max_value;
}

int main(){
    
    cin >>R>>C;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cache[i][j] = -1;
            cin >> a[i][j];
            
        }
    }
    
    int max = 0;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            int t = find(i,j);
            if (t>max){
                max = t;
            }
        }
    }
    cout<<max+1<<endl;
    return 0;
}


