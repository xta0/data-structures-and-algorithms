#include <iostream>
#include <cmath>
#include <vector>

int limit;
int MAX;
int num;
int r;

using namespace std;

struct node{
    int left;
    int right;
    vector<int> elements;
    vector<node* >children;
    node(){left = right = 0;}
    node(int l, int r):left(l),right(r){}
    const int value() const{
        return left+right;
    }
    void set_elements(int l, int r, vector<int> parents){
        elements.push_back(l);
        elements.push_back(r);
        for(int i=1; i<parents.size();i++){
            elements.push_back(parents[i]);
        }
    }
};

ostream& operator<<(ostream& o, vector<int>& v){
    o<<"[ ";
    for(auto x : v){
        cout<<x<<",";
    }
    o<<" ]";
    return o;
}

void log_tree(node* root){
    cout<<"--"<<endl;
    cout<<"left: "<<root->left<<"| right: "<<root->right<<endl;
    cout<<"value: "<<root->value()<<endl;
    cout<<"elements: "<<root->elements<<endl;
    for(auto sub : root->children){
        log_tree(sub);
    }
}
void tree(node* root){
    int left = root->left;
    int i = 1;
    int factor = 10;
    while(left/factor != 0){
        int l = left/factor;
        int r = left%factor;
        node* c = new node();
        c->left = l;
        c->right = root->right + r;
        c->set_elements(l, r, root->elements);
        root->children.push_back(c);
        i++;
        factor = pow(10.0, i);
    }

    for(auto node : root->children){
        tree(node);
    }
}
void calculate(node* root){
    
}
using namespace std;
int main(){
    
    limit = num  = -1;
    while(limit != 0 && num != 0){
        cin >> limit >> num;
        if( limit == num){
            break;
        }else{
            node* root = new node(num,0);
            tree(root);
            log_tree(root);
        }
    }
    
    return 0;
}
