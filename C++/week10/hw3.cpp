#include <iostream>
using namespace std;
/*
输入
第一行是一个整数 t (t <= 10)，表示数据组数；
每组输入数据包含两行，第一行是一个整数 n (n <= 100)，
第二行是 n 个用空格分隔开的整数
2
2
4 3
3
0 1 2

输出
25
5
*/

// 在此处补充你的代码
typedef int(*fptr)(int);
int sum(int* p, int sz, fptr ptr){

    int s = 0;
    for(int i=0;i<sz;i++){
        s+=ptr(p[i]);
    }
    return s;
}
int sqr(int n) {
    return n * n;
}
int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}