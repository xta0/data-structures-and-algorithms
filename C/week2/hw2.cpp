#include <iostream>
using namespace std;

int main()
{

    for (int py = 1; py <= 4; py++)
    {
        for (int dt = 1; dt <= 4; dt++)
        {
            for (int t = 1; t <= 4; t++)
            {
                for (int h = 1; h <= 4; h++)
                {
                    if (py != dt && py != t && py != h && dt != t && dt != h && h != t)
                    {
                        if (
                            ((dt == 1) + (py == 3) + (h == 4) == 1) &&
                            ((h == 1) + (py == 2) + (t == 3) + (dt == 4) == 1) &&
                            ((dt == 3) + (h == 4) == 1) &&
                            ((py == 1) + (h == 2) + (dt == 3) + (t == 4) == 1))
                        {
                            cout << py << endl;
                            cout << dt << endl;
                            cout << t << endl;
                            cout << h << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}