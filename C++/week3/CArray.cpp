#include <iostream>
#include <cstdlib>

using namespace std;

// template <T>
class CArray{
    
private:
    int *p = nullptr;
    size_t  c = 0;
    size_t  l= 0; //current length
    
public:
    CArray():CArray(0){}
    CArray(int n){
        if(p){
            delete[] p;
        }
        l = n;
        c = l+10;
        p = new int[c];
        memset(p,0,sizeof(int)*c);
    }
    CArray(const CArray& array){
        
        if(p){
            delete[] p;
            p = nullptr;
        }
        const int *pSrc = array.data();
        if(pSrc){
            memcpy(p,pSrc,sizeof(int)*array.capacity());
        }
        c = array.capacity();
        l = array.size();
    }
    ~CArray (){
        if(p){
            delete[] p;
            p = nullptr;
        }
    }
    
    size_t capacity() const{
        return c;
    }
    size_t size() const{
        return l;
    }
    const int* data() const{
        return p;
    }
    void push_back(int x){
        if(l + 1 < c){
            p[l]=x;
            l++;
        }else{
            //
            cout<<"re-allocation "<<endl;
            c = l+10;
            int *r = new int[c];
            memcpy(r,p,l*sizeof(int));
            if(p){
                delete[] p;
                p = nullptr;
            }
            p = r;
            p[l] = x;
            l++;
        }
    }
    int operator[](int index){
        if(index >= l){
            throw -1;
        }else{
            return p[index];
        }
    }
    CArray& operator=(CArray& array){
        if(p == array.data()){
            return *this;
        }
        if(p){
            delete[] p;
            p = nullptr;
        }
        const int *pSrc = array.data();
        if(pSrc){
            memcpy(p,pSrc,sizeof(int)*array.capacity());
        }
        c = array.capacity();
        l = array.size();
        return *this;
    }
    int operator=(int x){


        return x;
    }
};

int main(){
    
    CArray a;
    for(int i=0; i<5; ++i){
        a.push_back(i);
    }
    cout<<"a.size(): "<<a.size()<<endl;
    cout<<"a.capacity(): "<<a.capacity()<<endl;

    CArray a2,a3;
    a2 = a;

    for(int i=0; a.size(); ++i){
        cout<<a2[i];
    }

    a3 = a2;
    
    for(int i=0; i<a2.size(); ++i){
        cout<<a[i];
    }
    cout<<endl;

    // a[3]=100;



    return 0;
}
