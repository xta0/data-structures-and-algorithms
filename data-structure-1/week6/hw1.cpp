#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;



struct HuffmanTreeNode{
    HuffmanTreeNode* left = NULL;
    HuffmanTreeNode* right = NULL;
    HuffmanTreeNode* parent = NULL;
    int weight = 0;
    bool isVisited = false;
    
};

struct comp{
    bool operator()(HuffmanTreeNode* l1, HuffmanTreeNode* l2){
        return l1->weight > l2->weight;
    }
};

struct HuffmanTree{
    HuffmanTreeNode* root;
    HuffmanTree(vector<int>& weight){
        priority_queue<HuffmanTreeNode*,std::vector<HuffmanTreeNode* >,comp> heap;
        size_t n = weight.size();
        for(int i=0; i<n; ++i){
            HuffmanTreeNode* node = new HuffmanTreeNode();
            node->weight = weight[i];
            node->left = node->right = node->parent = NULL;
            heap.push(node);
        }
        for(int i=0; i<n-1; i++){ //两个节点合成一个，共有n-1次合并建立Huffman树
            HuffmanTreeNode* first = heap.top();
            heap.pop();
            HuffmanTreeNode* second = heap.top();
            heap.pop();
            HuffmanTreeNode* parent = new HuffmanTreeNode();
            first->parent = parent;
            second->parent = parent;
            parent->weight = first->weight + second->weight;
            parent->left  = first;
            parent->right = second;
            heap.push(parent);
            root = parent;
        }
    }
    
    HuffmanTreeNode* find_node(int weight){
        HuffmanTreeNode* ret = NULL;
        
        //bfs
        queue<HuffmanTreeNode* > qq;
        qq.push(root);
        while(!qq.empty()){
            HuffmanTreeNode* front = qq.front();
            qq.pop();
            if(front -> weight == weight &&
               front->left == NULL &&
               front->right == NULL &&
               front->isVisited == false){
                
                ret = front;
                ret->isVisited = true;
                break;
            }
            if(front->left){
                qq.push(front->left);
            }
            if(front->right){
                qq.push(front->right);
            }
        }
        
        
        return ret;
    }
    
    string code(int weight){
        string ret("");
        HuffmanTreeNode* node = find_node(weight);
        stack<char> ss;
        while(node){
            HuffmanTreeNode* parent = node->parent;
            if(!parent){
                break;
            }
            if(node == parent->left){
                ss.push('0');
            }else{
                ss.push('1');
            }
            node = node->parent;
        }
        while(!ss.empty()){
            ret+=string(1,ss.top());
            ss.pop();
        }
        
        return ret;
    }
        
};

int main(){
    vector<int> vec;
    int n=0,num;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> num;
        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());
    
    HuffmanTree tree = HuffmanTree(vec);
    int sum = 0;
    for(int i=0;i<vec.size();++i){
        string code = tree.code(vec[i]);
        sum += vec[i]*code.length();
    }
    cout<<sum<<endl;
    
    return 0;
}
