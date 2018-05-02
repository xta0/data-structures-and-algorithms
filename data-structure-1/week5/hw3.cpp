#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(string str): val(str){
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

void preOrder(TreeNode* root){
    if(root && root->val != "*"){
        cout<<root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void InOrder(TreeNode* root){
    if(root && root->val != "*"){
        InOrder(root->left );
        cout<<root->val;
        InOrder(root->right);
    }
}
void PostOrder(TreeNode* root){
    if(root  && root->val != "*"){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->val;
    }
}
void deleteTree(TreeNode* root){
    if(!root){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    
    delete root;
    root = NULL;
}

queue<string>qq;

TreeNode* buildTree(size_t level){
    if(qq.empty()){
        return NULL;
    }
    string str = qq.front();
    size_t len = str.length()-1;
    
    if(len == level){
        char ch = str[len];
        qq.pop();
        if(ch == '*'){
            return NULL;
        }
        TreeNode* node = new TreeNode(string(1,ch));
        node->left = buildTree(level+1);
        node->right = buildTree(level+1);
        
        return node;
    }else{
        return NULL;
    }
}


int main(){
    int n = 0;
    cin >>n;
    for(int i=0;i<n;++i){
        TreeNode* root = NULL;
        string input;
        cin>>input;
        while(input != "0"){
            qq.push(input);
            cin>>input;
        }
        
        root = buildTree(0);
        preOrder(root); cout<<endl;
        PostOrder(root); cout<<endl;
        InOrder(root); cout<<endl;
        cout<<endl;
        deleteTree(root);
    }
    
    return 0;
}
