#include <set>
#include <iostream>

using namespace std;
int main()
{
    multiset<int> mset;
    set<int> sset;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s == "add"){
            int x;
            cin>>x;
            mset.insert(x);
            sset.insert(x);
            cout<<mset.count(x)<<endl;
        }
        else if(s=="del"){
            int x;
            cin >> x;
            cout<<mset.count(x)<<endl;  
            mset.erase(x);
             
        }else if(s=="ask"){
            int x;
            cin>>x;
            set<int>::iterator it = sset.find(x);
            if(it != sset.end()){
                cout<<"1 ";
            }else{
                cout<<"0 ";
            }
            cout<<mset.count(x)<<endl;  

        }
        else{
            cout<<"wrong input!";
        }
    }
}