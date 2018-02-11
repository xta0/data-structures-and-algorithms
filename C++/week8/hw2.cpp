#include <iostream>
#include <map>
#include <list>
#include <string>
#include <cstring>
#include <iterator>  
using namespace std;

class MyList
{
  private:
    list<int> data;
    int id;

  public:
    MyList()
    {
        id = 0;
        data = list<int>(0);
    }
    MyList(int _id)
    {
        id = _id;
        data = list<int>(0);
    }
    virtual ~MyList() {}
    int get_id() const
    {
        return id;
    }
    list<int> get_data() const
    {
        return data;
    }
    void add_number(int num)
    {
        data.push_back(num);
        data.sort();
    }
    void merge(MyList *other)
    {
        list<int> l = other->get_data();
        data.merge(l);
        data.sort();
    }
    void empty()
    {
        data.clear();
    }
    void unique()
    {
        data.sort();
        data.unique();
    }
    void out()
    {
        data.sort();
        list<int>::iterator it = data.begin();
        for (; it != data.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};

/*
 16
 new 1
 new 2
 add 1 1
 add 1 2
 add 1 3
 add 2 1
 add 2 2
 add 2 3
 add 2 4
 out 1
 out 2
 merge 1 2
 out 1
 out 2
 unique 1
 out 1
 */

int main()
{
    map<int, MyList *> lmap;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s == "new")
        {
            int id;
            cin >> id;
            MyList *list = new MyList(id);
            lmap[id] = list;
        }
        else if (s == "add")
        {
            int id, num;
            cin >> id >> num;
            MyList *list = lmap[id];
            list->add_number(num);
        }
        else if (s == "merge")
        {
            int id1, id2;
            cin >> id1 >> id2;
            MyList *list1 = lmap[id1];
            MyList *list2 = lmap[id2];
            list1->merge(list2);
            list2->empty();
        }
        else if (s == "unique")
        {
            int id;
            cin >> id;
            MyList *list = lmap[id];
            list->unique();
        }
        else if (s == "out")
        {
            int id;
            cin >> id;
            MyList *list = lmap[id];
            list->out();
        }
    }

    map<int, MyList *>::iterator it = lmap.begin();
    for (; it != lmap.end(); it++)
    {
        MyList *p = it->second;
        if (p)
        {
            delete p;
            p = NULL;
        }
    }
    lmap.clear();

    return 0;
}
