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


int main(){
    int n = 0;
    cin >>n;
    cin.get();
    for(int i=0;i<n;++i){
        string str("");
        TreeNode* root = NULL;
        TreeNode* tmp = NULL;
        int layer = 0;
        while (getline(cin , str)) {
            if(str != "0"){
                if(!root){
                    root = new TreeNode(str);
                    tmp = root;
                }else{
                    int len = (int)str.length();
                    char c = str[len-1];
                    len -= 1;
                    TreeNode* node = new TreeNode(string(1,c));
                    if(len > layer){
                        node -> parent = tmp;
                        if(tmp->left == NULL){
                            tmp -> left = node;
                        }else{
                            tmp->right = node;
                        }
                        if(c != '*'){
                            layer++;
                            tmp = node;
                        }
                    }
                    else if(len == layer){
                        if(c!='*'){
                            TreeNode* parent = tmp->parent;
                            if(parent->left == NULL){
                                parent -> left = node;
                            }else{
                                parent->right = node;
                            }
                            node ->parent = tmp;
                            tmp = node;
                        }
                    }
                    else{
                        while(tmp->parent){
                            tmp = tmp->parent;
                            layer --;
                            if(layer == len){
                                break;
                            }
                        }
                        TreeNode* parent = tmp->parent;
                        node->parent = parent;
                        if(parent->left == NULL){
                            parent->left = node;
                            tmp = node;
                        }else{
                            parent->right = node;
                            tmp = node;
                        }
                    }
                }
            }else{
                break;
            }
        }
        
        preOrder(root);
        cout<<endl;
        PostOrder(root);
        cout<<endl;
        InOrder(root);
        cout<<endl;
        
        if(i!=n-1){
            cout<<endl;
        }
        
    }
   
    
    
    return 0;
}
