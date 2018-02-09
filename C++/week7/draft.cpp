#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class MyException : public exception
{
  public:
    virtual const char *what() const throw()
    { // const throw 意思是这个函数不会抛出异常
        return "MyExcepiton!";
    }
};

void throwException() throw()
{
    throw MyException();
}

#pragma pack(push, 1)
struct Person{
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

#define EXCEPTION 0
#define FILE 0
#define WRITE_STRUCT 1
int main()
{
    cout << 25u - 50 << endl;
#if FILE
    fstream fout("text.txt", ios::out);
    if (fout.is_open())
    {
        fout << "Hello there" << endl;
        fout << 123 << endl;
        fout.close();
    }
    else
    {
        cout << "Could not create file: text.txt" << endl;
    }
    ifstream fin("text.txt");
    if (fin.is_open())
    {
        string line;
        //使用getline
        while (!fin.eof())
        {
            getline(fin, line);
            cout << line << endl;
            fin >> ws; //抛弃掉line末尾的换行
            if (!fin){
                break;
            }
        }
        fin.close();
    }
    else
    {
        cout << "Could not read file: text.txt" << endl;
    }
#endif

#if WRITE_STRUCT
    Person someone{"Frodo",220, 0.8};
    ofstream fout{"test.bin",ios::binary};
    fout.write(reinterpret_cast<char*>(&someone), sizeof(Person));
    fout.close();
    //
    Person frodo = {};
    ifstream fin{"test.bin",ios::binary};
    fin.read(reinterpret_cast<char*>(&frodo), sizeof(Person));
    fin.close();
    cout<<frodo.name<<" "<<frodo.age<<" "<<frodo.height<<endl;
#endif

#if EXCEPTION
    try
    {
        throwException();
    }
    catch (MyException &e)
    {
        cout << e.what() << endl;
    }
#endif
}