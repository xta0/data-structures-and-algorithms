#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int maze[5][5];
struct PT{
    int x;
    int y;
    PT(int _x,int _y){
        x = _x;
        y = _y;
        parent = NULL;
    }
    PT* parent;
};


void log_path(PT* point){
    stack<PT* > points;
    while(point){
        points.push(point);
        point = point->parent;
    }
    while(!points.empty()){
        PT* point = points.top();
        cout<<"("<<point->x<<", "<<point->y<<")"<<endl;
        points.pop();
    }
    
}
void tree(PT* root){
    
    queue<PT* >q;
    q.push(root);
    
    while(!q.empty()){
        
        PT* point = q.front();
        int i = point->x;
        int j = point->y;
        if(i == 4 && j == 4){
            log_path(point);
            break;
        }else{
            //left
            if(j-1>=0 && maze[i][j-1] == 0){
                PT* pt = new PT(i,j-1);
                pt->parent = point;
                q.push(pt);
            }
            //up
            if(i-1 >= 0 && maze[i-1][j] == 0){
                PT* pt = new PT(i-1,j);
                pt->parent = point;
                q.push(pt);
            }
            
            //bottom
            if(i+1 <= 4 && maze[i+1][j] == 0){
                PT* pt = new PT(i+1,j);
                pt->parent = point;
                q.push(pt);
            }
            //right
            if(j+1<=4 && maze[i][j+1] == 0){
                PT* pt = new PT(i,j+1);
                pt->parent = point;
                q.push(pt);
            }
        }

        q.pop();
    }
}

int main(){
    for(int i=0;i<5; i++){
        for(int j=0;j<5;j++){
            cin>>maze[i][j];
        }
    }
    PT* root = new PT(0,0);
    tree(root);

    return 0;
}
