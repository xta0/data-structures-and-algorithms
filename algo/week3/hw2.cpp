#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Node{
public:
    string name;
    vector<Node* > children;
    ~Node(){
        cout<<__func__<<": "<<name<<endl;
    }
};

void clean(Node* root){
    root -> name = "";
    root -> children.clear();
}

void print(Node* root){
    cout<<root->name<<endl;
    if(root->children.size() > 0){
        for(auto node : root->children){
            if(node -> children.size() > 0){
                cout<<"|     "<<node->name<<endl;
                print(node);
            }else{
                cout<<node->name<<endl;
            }
        }
    }
}
void fill(Node* root){
    string tmp;
    cin >> tmp;
    if (tmp != "]"){
        char x = tmp[0];
        if(x == 'f' || x == 'd'){
            Node* n = new Node{tmp,{}};
            if(x == 'd'){
                fill(n);
            }
            root->children.push_back(n);
        }
    }
}

void tree(Node& root){
    string tmp;
    int count = 1;
    while(tmp != "#"){
        cin >> tmp;
        if(tmp == "*"){
            print(&root);
        }else{
            cout<<"DATA SET "<<count<<":"<<endl;
            fill(&root);
            clean(&root);
            count ++;
        }
    }
}

int main(){
    Node root = {"ROOT",{}};
    tree(root);
    return 0;
}