#include <stdio.h>  
#include <iostream>  
using namespace std;  
  
#define MAXNODE 1024  
char NodeInfoSeq[MAXNODE * 2];  
char OutputDump[MAXNODE];  
typedef struct fake_bt_node  
{  
    char info;  
    struct fake_bt_node *lc;  
    struct fake_bt_node *rc;  
} fbtn;  
fbtn* nStack[MAXNODE];  
fbtn* nQueue[MAXNODE * 2]; //front可能推到很后很后，所以队列空间开大一点  
  
fbtn *BuildFakeBinaryTree(int n)  
{  
    int sp = -1; //栈指针sp，栈空时为-1。栈顶为当前的父结点。  
    //先建立树根结点  
    fbtn *root = new fbtn;  
    root->info = NodeInfoSeq[0];  
    root->lc = NULL;  
    root->rc = NULL;  
    //树根结点进栈  
    nStack[++sp] = root;  
  
    for (int i = 2; i < 2 * n; i += 2)  
    {  
        //根据输入序列新建一个结点  
        fbtn *temp = new fbtn;  
        temp->info = NodeInfoSeq[i];  
        temp->lc = NULL;  
        temp->rc = NULL;  
        //接下来，把这个新结点连在伪满二叉树上  
        fbtn *curFa = nStack[sp]; //栈顶结点是当前结点的父亲  
        if (curFa->lc == NULL) //当前结点是左儿子  
            curFa->lc = temp;  
        else if (curFa->rc == NULL) //当前结点是右儿子  
            curFa->rc = temp;  
        else //curFa的左、右儿子都有，说明curFa不是当前结点的父亲结点，那就退栈，找当前结点的父亲结点，且当前结点一定是右儿子  
        {  
            while (nStack[sp]->rc != NULL)  
                --sp;  
            nStack[sp]->rc = temp;  
        }  
        if (NodeInfoSeq[i + 1] == '0') //如果新结点是内部结点，那么它一定是父亲，要进栈  
            nStack[++sp] = temp;  
    }  
    return root;  
}  
  
void PrintMirrorImage(fbtn *root)  
{  
    int qf = 0, qr = -1; //分别表示queue front和queue rear  
    int sp = -1;  
    int dp = -1; //表示OutputDump  
    fbtn* head;  
    nQueue[++qr] = root; //根节点入队  
    //宽度优先遍历  
    while (qr + 1 != qf)  
    {  
        head = nQueue[qf++];  
        OutputDump[++dp] = head->info;  
//再把head的所有儿子都入队，由于要输出镜像，所以要反向入队，我们借助栈来完成。  
        if (head->lc) //head是有儿子的(if head has a child node)  
        {  
            fbtn *cc = head->lc; //cc指当前的子节点(cc means current child node)  
            //出栈，入队，使子节点逆序  
            while (cc != NULL)  
            {  
                nStack[++sp] = cc;  
                cc = cc->rc;  
            }  
            while (sp != -1)  
                nQueue[++qr] = nStack[sp--];  
        }  
    }  
    //打印输出序列(print the output sequence)  
    for (int i = 0; i <= dp; i++)  
    {  
        if (OutputDump[i] != '$')  
            cout << OutputDump[i] << ' ';  
    }  
}  
  
//释放树的内存(free the memory)  
void DeleteFakeBinaryTree(fbtn *root)  
{  
    if (root != NULL)  
    {  
        DeleteFakeBinaryTree(root->lc);  
        DeleteFakeBinaryTree(root->rc);  
        delete root;  
        root = NULL;  
    }  
}  
  
int main()  
{  
    int n, i = 0;  
    char c;  
    cin >> n;  
    getchar(); //取走数字n后面的换行符  
    while ((c = getchar()) != '\n')  
    {  
        if (c != ' ')  
            NodeInfoSeq[i++] = c;  
    }  
    fbtn *root = BuildFakeBinaryTree(n);  
    PrintMirrorImage(root);  
    DeleteFakeBinaryTree(root);  
    return 0;  
}  