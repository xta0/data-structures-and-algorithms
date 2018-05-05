#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct HuffmanTreeNode{
    HuffmanTreeNode* left = NULL;
    HuffmanTreeNode* right = NULL;
    HuffmanTreeNode* parent = NULL;
    int weight = 0;
};

struct comp{
    bool operator()(HuffmanTreeNode* l1, HuffmanTreeNode* l2){
        return l1->weight > l2->weight;
    }
};

HuffmanTreeNode* buildHuffmanTree(vector<int>& weight){
    HuffmanTreeNode* root = NULL;
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
    
    return root;
}

typedef multimap<int, vector<int> > mmid;
void traverse(HuffmanTreeNode* root, vector<int>& codes, mmid& dictionary){
    
    if(root&&root->left==NULL&&root->right==NULL){
//        cout<<root->weight<<": ";
//        cout<<codes<<endl;
////        dictionary[root->weight] = codes;
        dictionary.insert(mmid::value_type(root->weight, codes));
    }
    
    if(root->left){
        codes.push_back('0');
        traverse(root->left,codes,dictionary);
        codes.pop_back(); //回溯
    }
    
    if(root->right){
        codes.push_back('1');
        traverse(root->right, codes,dictionary);
        codes.pop_back();//回溯
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
    
    HuffmanTreeNode* root = buildHuffmanTree(vec);
    vector<int> codes;
    mmid dict;
    traverse(root, codes,dict);
    int sum = 0;
    mmid::iterator it = dict.begin();
    for(;it != dict.end(); ++it){
        mmid::value_type pair = *it;
        int k = pair.first;
        vector<int> code =pair.second;
        sum += k*code.size();
    }
    cout<<sum<<endl;
    return 0;
}
