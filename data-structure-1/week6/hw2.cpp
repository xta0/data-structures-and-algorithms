#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

struct BSTNode{
    int val = 0;
    BSTNode* left = NULL;
    BSTNode* right = NULL;
    BSTNode(int v):val(v){}
};

void traverse(BSTNode* root){
    if(root){
        cout<<root->val<<" ";
        traverse(root->left);
        traverse(root->right);
    }
}

int main(){
    string str;
    queue<int> qq;
    BSTNode* root = NULL;
    getline(cin, str);
    char* buff = (char* )str.c_str();
    char* c = strtok(buff, " \t");
    while(c){
        int num = atoi(c);
        qq.push(num);
        c = strtok(NULL, " \t");
    }
    while(!qq.empty()){
        int num = qq.front();
        qq.pop();
        BSTNode* node = new BSTNode(num);
        BSTNode* tmp = root;
        if(!root){
            root = tmp = node;
        }else{
            while(true){
                if(num > tmp->val){
                    if(tmp->right != NULL){
                        tmp = tmp->right;
                    }else{
                        tmp->right = node;
                        break;
                    }
                }else if(num == tmp->val){
                    break;
                }else{
                    if(tmp->left){
                        tmp = tmp->left;
                    }else{
                        tmp->left = node;
                        break;
                    }
                }
            }
        }
    }
    traverse(root);
    
    return 0;
}
