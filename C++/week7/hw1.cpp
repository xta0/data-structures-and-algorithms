#include <iostream>
using namespace std;
// 在此处补充你的代码
#include <vector>

template <class T>
class CArray2D{
    vector<vector<T>> arr2d={0,{0,0}};
public:
    CArray2D (
              unsigned int row,
              unsigned int column){
        arr2d = {row,{static_cast<int>(column)}};
    };
    vector<T>& operator[](int index){
        return arr2d[index];
    }
};

template <class T>
class CArray3D{
    
private:
    // vector<CArray2D<T>> arr3d={0,{0,0}};
    vector<vector<vector<T>>> arr3d;
    
public:
    CArray3D(
             unsigned int zindex,
             unsigned int row,
             unsigned int column){
        // arr3d = {zindex,{row,column}};
        arr3d = {zindex,{row,{static_cast<int>(column)}}};
    }
    // CArray2D<T>& operator[](int index){
    //     return arr3d[index];
    // }
    vector<vector<T>>& operator[](int index){
        return arr3d[index];
    }
};
int main()
{
    // CArray3D<int> a(3,4,5);
    // int No = 0;
    // for( int i = 0; i < 3; ++ i )
    //     for( int j = 0; j < 4; ++j )
    //         for( int k = 0; k < 5; ++k )
    //             a[i][j][k] = No ++;
    // for( int i = 0; i < 3; ++ i )
    //     for( int j = 0; j < 4; ++j )
    //         for( int k = 0; k < 5; ++k )
    //             cout << a[i][j][k] << ",";
    
    int No=0;
    CArray2D<int> b(4,5);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            b[i][j] =No++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<b[i][j]<<",";
        }
    }
    return 0;
}
