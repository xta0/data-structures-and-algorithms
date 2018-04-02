#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int limit=-1;
int MAX=0;
bool error = true;
bool rejected = false;
int result_sum = 0;
vector<int> result_list;


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
    for(int i=0;i<v.size();++i){
        int x = v[i];
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
    for(int i=0;i<root->children.size();++i){
        node* sub = root->children[i];
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
    
    for(int i=0;i<root->children.size();++i){
        node* sub = root->children[i];
        tree(sub);
    }
}
void calculate(node* root){
    for(int i=0;i<root->children.size();++i){
        node* sub = root->children[i];
        calculate(sub);
    }
    int value = root->value();
    if(value <= limit){
        if(value > MAX ){
            MAX = value;
            result_list = root->elements;
            result_sum = root->value();
            rejected = false;
            error = false;
        }else if (value == MAX){
            rejected = true;
        }
    }
}
void clear_state(){
    
    rejected = false;
    error = true;
    result_list.clear();
    result_sum = 0;
    limit=-1;
    MAX=0;
}
using namespace std;
int main(){
    int num;
    while(true ){
        clear_state();
        cin >> limit >> num;
        if(limit == 0 && num == 0){
            break;
        }
        if( limit == num){
            cout<<num<<" "<<limit<<endl;
            continue;
        }else{
            node* root = new node(num,0);
            tree(root);
//            log_tree(root);
            calculate(root);
            if(error){
                cout<<"error"<<endl;
                continue;
            }
            if(!error && rejected){
                cout<<"rejected"<<endl;
                continue;
            }
            cout<<result_sum;
            if(result_list.size() > 0){
                for(int i=0;i<result_list.size();++i){
                    cout<<" "<<result_list[i];
                }
            }else{
                cout<<" "<<root->value();
            }
            cout<<endl;
        }
    }
    
    return 0;
}

