#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n=0, k = 0;
    cin>>n>>k;
    // priority_queue<int,vector<int>,greater<int> > pq;
    priority_queue<int> pq;
    int tmp = 0;
    for(int i=0;i<k;i++){
        cin >> tmp;
        pq.push(tmp);
    }
    for(int i = k; i<n; i++){
        cin >> tmp;
        if(tmp < pq.top()){
            pq.pop();
            pq.push(tmp);
        }
    }
    cout<<pq.top()<<endl;
    return 0;
}
