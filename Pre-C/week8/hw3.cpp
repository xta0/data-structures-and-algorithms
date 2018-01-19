
#include <iostream>

using namespace std;
int main()
{
    double n = 0, k = 0;

    while (cin >> n >> k)
    {
        double s = 200;
        double i = n;
        double y = 1;
        while (i < s)
        {
            i = i + n;
            s = s + s * (k / 100.0);
            
            y++;

            if (y > 20){
                break;
            }
        }
        if (y <= 20){
            cout << y << endl;
        }
        else{
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
