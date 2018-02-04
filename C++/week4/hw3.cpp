#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
// template <T>
class Array2
{

  private:
    int *p = nullptr;
    int co = 0;
    int ro = 0;

  public:
    Array2() : Array2(0, 0) {}
    Array2(int m, int n)
    {
        if (p)
        {
            delete[] p;
        }
        co = n;
        ro = m;
        size_t sz = co * ro * sizeof(int);
        p = new int[sz];
        memset(p, 0, sz);
    }
    Array2(const Array2 &array)
    {

        if (p)
        {
            delete[] p;
            p = nullptr;
        }
        const int *pSrc = array.data();
        if (pSrc)
        {
            co = array.column();
            ro = array.row();
            size_t sz = co * ro * sizeof(int);
            p = new int[sz];
            memcpy(p, pSrc, sz);
        }
    }
    ~Array2()
    {
        if (p)
        {
            delete[] p;
            p = nullptr;
        }
    }
    size_t column() const
    {
        return co;
    }
    size_t row() const
    {
        return ro;
    }
    const int *data() const
    {
        return p;
    }
    int *operator[](int index)
    {
        return &p[index * co];
    }

    int operator()(int x, int y)
    {
        return p[x * co + y];
    }

    Array2 &operator=(Array2 &array)
    {
        if (p == array.data())
        {
            return *this;
        }
        if (p)
        {
            delete[] p;
            p = nullptr;
        }
        const int *pSrc = array.data();
        if (pSrc)
        {
            co = array.column();
            ro = array.row();
            size_t sz = co * ro * sizeof(int);
            p = new int[sz];
            memcpy(p, pSrc, sz);
        }
        return *this;
    }
};

int main()
{
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}