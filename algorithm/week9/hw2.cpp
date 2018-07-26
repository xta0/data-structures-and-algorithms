#include <iostream>
#include <numeric>

using namespace std;
int main()
{
    int N, S;
    cin >> N >> S;
    int P = 5000;
    long long costs = 0;
    for (int i = 0; i < N; ++i)
    {
        int C, Y;
        cin >> C >> Y;
        P = min(P + S, C);
        costs += P * Y;
    }
    cout << costs << endl;
    return 0;
}
