#include <iostream>
#include <algorithm>
#include <vector>
// 7
// 4 2 1 2 2 2 3 1 2 3 5 0 1 4
using namespace std;

struct Point{
    int x;
    int y;
    bool r;
};

bool _max_(Point* pt1, Point* pt2){
    return pt1->y < pt2->y;
}

bool _min_(Point p1, Point p2){
    return p1.x < p2.x;
}


int main(){
    
    int n=0;
    cin >> n;
    
    Point list[n];
    
    int x=0,y=0;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        Point* pt  = &list[i];
        pt->x = x;
        pt->y = y;
        pt->r = true;
    }
    
    //找到x,y最大值
    for(int i=0;i<n;i++){
        Point *pt1 = &list[i];
        // cout<<"current:"<<"("<<pt1->x<<","<<pt1->y<<")"<<endl;
        vector<Point*> tmp1,tmp2;
        for(int j=0; j<n; j++){
            if(j!=i){
                Point* pt2 = &list[j];
                if(pt2->x >= pt1->x){
                    tmp1.push_back(pt2);
                }
            }
        }
        if(tmp1.size() > 0){
            Point* max_pt = *max_element(tmp1.begin(), tmp1.end(),_max_);
            if(pt1->y > max_pt->y){
                pt1->r = true;
            }else{
                pt1->r=false;
            }
            tmp1.empty();
//            cout<<"max compare: "<<"("<<max_pt->x<<","<<max_pt->y<<")"<<endl;
//            cout<<"result:"<<pt1->r<<endl;
            continue;
        }else{
//            cout<<"result:"<<pt1->r<<endl;
        }

    }
    
    vector<Point> results;
    for(int i=0;i<n;i++){
        Point pt = list[i];
        // cout<<"{x:"<<pt.x<<",y:"<<pt.y<<",r:"<<pt.r<<"}"<<endl;
        if(pt.r){
            results.push_back(pt);
        }
    }
    sort(results.begin(), results.end(), _min_);
    
    for(int i=0;i<results.size();i++){
        Point pt = results[i];
        cout<<"("<<pt.x<<","<<pt.y<<")";
        if(i!=results.size()-1){
            cout<<",";
        }
    }
    
    return 0;
}

