#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
public:
    string name;
    int layer;
    vector<Node* > children;
    Node(string name, int layer):name(name),layer(layer){}
};

static int layer = 0;
static int round = 1;
static string token = "";

void clean_state(){
    layer = 0;
    round ++;
    token = "";
}

void clean_tree(Node* root){
    for(int i=0; i<root->children.size();++i){
        Node* node = root->children[i];
        if(node -> children.size() > 0){
            clean_tree(node);
        }
        if(node){
            delete node;
            node = NULL;
        }
    }
    root -> children.clear();
}

void print_node(Node* node){
    for(int i=0;i<node->layer;++i){
        cout<<"|     ";
    }
    cout<<node->name<<endl;
}

void print_tree(Node* root){
    print_node(root);
    for(int i=0; i<root->children.size();++i){
        Node* node = root->children[i];
        if(node -> children.size() > 0){
            print_tree(node);
        }else{
            print_node(node);
        }
    }
}

bool comp1(Node* n1, Node* n2){
    char c1 = n1->name[0];
    char c2 = n2->name[0];
    if(c1 == 'd' && c2 == 'd'){
        return false;
    }else if(c1 == 'f' && c2 == 'd'){
        return false;
    }else if(c1 == 'd' && c2 == 'f'){
        return true;
    }else{
        return n1->name<n2->name;
    }
}
void sort_tree(Node* root){
    for(int i=0; i<root->children.size();++i){
        Node* node = root->children[i];
        if(node -> children.size() > 0){
            sort_tree(node);
        }
    }
    sort(root->children.begin(), root->children.end(), comp1);
}
void print(Node* root){
    sort_tree(root);
    cout<<"DATA SET "<<round<<":"<<endl;
    print_tree(root);
    cout<<endl;
}

void tree(Node* root){

    while(token != "#"){
        if(token == "*"){
            if(root->layer > 0){
                return;
            }
            print(root);
            clean_tree(root);
            clean_state();
        }else{
            cin >> token;
            cin.get();
            if(token == "]"){
                bool ret = layer > 0;
                layer--;
                if(ret){
                    return;
                }
            }else{
                char x = token[0];
                if(x == 'f' || x == 'd'){
                    Node* n = new Node(token,layer);
                    if(x == 'd'){
                        layer++;
                        n -> layer = layer;
                        tree(n);
                    }
                    root->children.push_back(n);
                }
            }
        }
     
    }
}

int main(){
    Node root("ROOT",0);
    tree(&root);
    return 0;
}

