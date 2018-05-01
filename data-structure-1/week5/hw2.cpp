#include <iostream>
#include <queue>
using namespace std;

class Heap{
private:
    vector<int> tree;
    int left(int i){
        return tree[2*i + 1];
    }
public:
    Heap(){}
    void push(int val){
        tree.push_back(val);
        //compare 

    }
    void pop(){
        cout<<tree.front()<<endl;
        // tree.pop();
    }
    int top(){
        return tree.front();
    }
private:
    void build(){

    }
};


int main(){
    Heap heap;
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        int n=0;
        cin >> n;
        while(n > 0){
            int cmd, num;
            cin >> cmd;
            if(cmd == 1){
                cin >> num;
                heap.push(num);
            }else if(cmd == 2){
                cout<<heap.top()<<endl;
                heap.pop();
            }
            n--;
        }
    }
    
    return 0;
}
