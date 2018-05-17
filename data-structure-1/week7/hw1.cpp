#include<iostream>  
#include<queue>  
#include<string>  
#include<algorithm>  
using namespace std;  
struct node  
{  
    char a;  
    int degree;  
    node *child[26];  
    node(char c, int d) :a(c), degree(d){}  
};  
node* creat() //建树  
{  
    char name;  
    int child_num, i;  
    node *next,*cur,*root;  
    queue <node*> q_root; //存放待处理节点的父节点(store parent node)  
    cin >> name >> child_num;  
    root = new node(name,child_num);  
    q_root.push(root);  
    while (!q_root.empty())  
    {  
        cur = q_root.front();  
        q_root.pop();  
        for (i = 0; i < cur->degree; ++i)  
        {  
            cin >> name >> child_num;  
            next = new node(name, child_num);  
            cur->child[i] = next;  
            q_root.push(next);  
        }  
    }  
    return root;  
}  
void post(node *root)  
{  
    if (root)  
    {  
        for (int i = 0; i < root->degree; i++)  
            post(root->child[i]);  
        cout << root->a << ' ';  
    }  
}  
int main()  
{  
    int  n;  
    cin >> n;  
    while (n--)  
    {  
        node *root = creat();  
        post(root);  
    }  
    return 0;  
}  