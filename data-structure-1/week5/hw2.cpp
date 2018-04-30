#include <iostream>
#include <queue>
using namespace std;


template <class T>
class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    
public:
    TreeNode(int x): val(x){}
};

template<class T>
class Heap{

TreeNode<T>* root = NULL;

public:
    Heap(){}
    void push(T val){
        if(!root){
            root = new TreeNode<T>(val);
        }else{
            //push
        }
    }
    void pop(){
        
    }
};


int main(){
    Heap<int>* heap;
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
//                qq.push(num);
            }else if(cmd == 2){
//                cout<<qq.top()<<endl;
//                qq.pop();
            }
            n--;
        }
    }
    
    return 0;
}
