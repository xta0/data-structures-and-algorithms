#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    cin >> n >> m;
    vector<int> vec;
    for(int i=1;i<=n;++i){
        vec.push_back(i);
    }
    
    int s=0;
    for(int i=vec.size(); i>1; i--){
        s = (s + m -1)%i;
        vec.erase( vec.begin()+s);
    }
    cout<<vec[0]<<endl;

    return 0;
}
