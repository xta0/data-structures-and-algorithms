#include <iostream>
using namespace std;
// 在此处补充你的代码

template <class T>
class CArray{
    T* data=NULL;
    int n=0;
public:
    CArray():CArray(0){}
    CArray(int n){
        // cout<<"Constructor-->"<<__FUNCTION__<<":"<<this<<endl;
    }
    ~CArray(){
        // cout<<"Destructor-->"<<__FUNCTION__<<":"<<this<<endl;
        if(data){
            delete data;
            data = NULL;
        }
    }
    void set(int _n){
        if(data){
            delete data;
            data = NULL;
        }
        n = _n;
        data = new T[_n];
    }
    T& operator[](int index){
        return data[index];
    }
};
template <class T>
class CArray2D{
    CArray<T>* data=NULL;
    int col=0;
    int row=0;
public:
    CArray2D():CArray2D(0,0){}
    CArray2D (int _row,int _col):col(_col),row(_row){};
    ~CArray2D(){
        if(data){
            delete [] data;data = NULL;
        }
    }
    void set(int _row, int _col){
        row=_row;
        col=_col;
        data = new CArray<T>[row];
        for(int i=0;i<_row; ++i){
            data[i].set(_col);
        }
    }
    CArray<T>& operator[](int index){
        return data[index];
    }
};

template <class T>
class CArray3D{
    CArray2D<T>* data=NULL;
    int col=0;
    int row=0;
    int z = 0;
public:
    CArray3D():CArray3D(0,0,0){}
    CArray3D (int _z , int _row,int _col):col(_col),row(_row),z(_z){
        data = new CArray2D<T>[z];
        for(int i=0; i<z; ++i){
            data[i].set(_row, _col);
        }
    };
    ~CArray3D(){
        if(data){
            delete [] data;data = NULL;
        }
    }
    CArray2D<T>& operator[](int index){
        return data[index];
    }
};
int main()
{
     CArray3D<int> a(3,4,5);
     int No = 0;
     for( int i = 0; i < 3; ++ i )
         for( int j = 0; j < 4; ++j )
             for( int k = 0; k < 5; ++k )
                 a[i][j][k] = No ++;
     for( int i = 0; i < 3; ++ i )
         for( int j = 0; j < 4; ++j )
             for( int k = 0; k < 5; ++k )
                 cout << a[i][j][k] << ",";
    
    return 0;
}

