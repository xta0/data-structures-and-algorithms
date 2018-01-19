#include<iostream>  
#include <iomanip>  
using namespace std;  
int main() {  
int patient=-1;  
int n;  
cin >> n;  
double a = 0;  
double b = 0;  
double c = 0;  
double d = 0;  
for (int i = 0; i<n; i++) {  
cin >> patient;  
if (patient <= 18)  
a++;  
  
  
if (patient <= 35 && patient >= 19)  
b++;  
if (patient <= 60 && patient >= 36)  
c++;  
if (patient>60)  
d++;  
}  
cout << "1-18: " << fixed << setprecision(2) << a / n * 100 << "%" << endl;  
cout << "19-35: " << fixed << setprecision(2) << b / n * 100 << "%" << endl;  
cout << "36-60: " << fixed << setprecision(2) <<c / n * 100 << "%" << endl;  
cout << "60-: " << fixed << setprecision(2) << d / n * 100 << "%" << endl;  
return 0;  
}  