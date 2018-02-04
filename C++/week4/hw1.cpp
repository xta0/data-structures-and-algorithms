#include <iostream>
//#include <cstring>
#include <cstdlib>
#include <string.h>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    Complex& operator=(char *str){
        
        size_t len = strlen(str);
        char tmp_buffer[len+1];
        strcpy(tmp_buffer, str);
        char* rc = strtok(tmp_buffer, "+");
        r = atof(rc);
        char* ic = strtok(NULL, "+");
        i = atof(ic);
        
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    
    return 0;
}
