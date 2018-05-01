
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MinHeap{
private:
    vector<int> tree;
    size_t left_child_index(size_t i){
        size_t index = 2*i + 1;
        if(index >= tree.size()){
            return -1;
        }else{
            return index;
        }
    }
    size_t right_child_index(size_t i){
        size_t index = 2*i + 2;
        if(index >= tree.size()){
            return -1;
        }else{
            return index;
        }
    }
    size_t parent_index(size_t i){
        if(i>0 && i<tree.size()){
            size_t index = floor((i-1)/2);
            return index;
        }else{
            return -1;
        }
    }
public:
    MinHeap(){}
    void push(int val){
        tree.push_back(val);
        bottom_up(tree.size()-1);
    }
    void pop(){
        if(tree.size() == 0){
            return ;
        }
        cout<<tree.front()<<endl;
        swap(tree.back(), tree.front());
        tree.pop_back();
        top_down(0);
    }
    int top(){
        return tree.front();
    }
    void clear(){
        tree.clear();
    }
    void log(){
        for(auto x: tree){
            cout<<x<<" ";
        }
        cout<<endl;
    }
private:
    void bottom_up(size_t i){
        //递归比较
        size_t p = parent_index(i);
        if(p == -1){
            return ;
        }
         if(tree[i]<tree[p]){
             swap(tree[i], tree[p]);
             bottom_up(p);
         }
    }
    void top_down(size_t i){
        //递归调整
        size_t l = left_child_index(i);
        size_t r = right_child_index(i);
        
        //一颗节点
        if(l == -1 && r == -1){
            return;
        }
        //左子树为空，说明当前已经是叶子节点
        else if(l == -1 ){
            return;
        }
        //右子树为空，比较左节点
        else if(r == -1 ){
            if(tree[i] > tree[l]){
                swap(tree[i], tree[l]);
                top_down(l);
            }
        }else{
            //左右子树都不空
            size_t index = tree[l] < tree[r] ? l:r;
            if(tree[i] > tree[index]){
                swap(tree[i],tree[index]);
                top_down(index);
            }
        }
    }
};


int main(){
        // MinHeap heap;
        // heap.push(9);
        // heap.push(8);
        // heap.push(10);
        // heap.push(6);
        // heap.push(12);
        // heap.push(4);
        // heap.push(7);
        // heap.push(1);
        // heap.log();
        // heap.pop();
        // heap.log();
        // heap.pop();
        // heap.log();
    
   MinHeap heap;
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
               heap.pop();
           }
           n--;
       }
       //clear heap
       heap.clear();
   }
    
    return 0;
}
