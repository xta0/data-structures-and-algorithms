
#include<iostream>  
#include<map>  
#include<string>  
using namespace std;  
map<string, int> sour; // the hash from sites to integer 0,1,..  
map<int, string> yuan;// the reversion of sour  
int p, q, r;  
#define maxn 40  
#define infi 1000000;  
class dist  
{  
public:  
    int len;  
    int pre;  
};  
dist D[maxn][maxn];  
void output(int s, int e) // print recursively  
{  
    if (s == e)  
    {  
        cout << yuan[s];  
        return;  
    }  
    output(s,D[s][e].pre);  
    cout << "->" << '(' << D[D[s][e].pre][e].len << ')' << "->" << yuan[e];  
}  
int main()  
{  
    string tem;  
    cin >> p;  
    for (int i = 0; i<p; i++)  
    {  
        cin >> tem;  
        sour.insert(pair<string, int>(tem, i));  
        yuan.insert(pair<int, string>(i, tem));  
  
    }  
    //initialize the matrix   
    for (int i = 0; i<p; i++)  
    {  
        for (int j = 0; j<p; j++)  
        {  
            if (i != j)  
            {  
                D[i][j].len = infi;  
                D[i][j].pre = -1;  
            }  
            else  
            {  
                D[i][j].len = 0;  
                D[i][j].pre = i;  
            }  
        }  
    }  
    cin >> q;  
    string fol1, fol2;  
    int len;  
    // modify the elements of the matrix.  
    for (int i = 0; i<q; i++)  
    {  
        cin >> fol1 >> fol2 >> len;  
        if (D[sour[fol1]][sour[fol2]].len>len)  
        {  
            D[sour[fol1]][sour[fol2]].len = len;  
            D[sour[fol1]][sour[fol2]].pre = sour[fol1];  
            D[sour[fol2]][sour[fol1]].len = len;  
            D[sour[fol2]][sour[fol1]].pre = sour[fol2];  
        }  
    }  
    int i, j, g;  
    // dynamic programming,Floy算法  
    for (g = 0; g<p; g++)  
    {  
        for (i = 0; i<p; i++)  
        {  
            for (j = 0; j<p; j++)  
            {  
                if (D[i][j].len > D[i][g].len + D[g][j].len)  
                {  
                    D[i][j].len = D[i][g].len + D[g][j].len;  
                    D[i][j].pre = D[g][j].pre;  
                }  
            }  
        }  
    }  
    cin >> r;  
    for (int i = 0; i<r; i++)  
    {  
        cin >> fol1 >> fol2;  
        output(sour[fol1], sour[fol2]);  
        cout << endl;  
    }  
    return 0;  
}  