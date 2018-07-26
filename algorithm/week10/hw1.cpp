#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t = 0, d = 0, n = 0;
struct Trash
{
    int x;
    int y;
    int value;
};
vector<Trash> trashes(21);
void enumerate()
{
    int max = 0;
    int max_count = 0;
    for (int y = 0; y < 1025; y++)
    {
        for (int x = 0; x < 1025; x++)
        {
            int temp = 0;
            for (int i = 0; i < n; i++){
                Trash trash = trashes[i];
                if (trash.x <= x + d &&
                    trash.x >= x - d &&
                    trash.y >= y - d &&
                    trash.y <= y + d){
                    temp += trashes[i].value;
                }
            }
            if (temp > max)
            {
                max = temp;
                max_count = 1;
            }
            else if (temp == max)
            {
                max_count++;
            }
        }
    }
    cout << max_count << " " << max << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> d >> n;
        for (int j = 0; j < n; ++j){
            cin >> trashes[j].x >> trashes[j].y >> trashes[j].value;
        }
        enumerate();
        trashes.clear();
    }
    return 0;
}
