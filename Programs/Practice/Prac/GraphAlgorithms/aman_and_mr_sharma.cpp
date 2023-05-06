#include <bits/stdc++.h>
using namespace std;

int runAroundCircle(int d, int r[], int x[])
{
    int cnt = 0;
    for (int i = 0; i < d; i++)
    {

        int p = (2 * 22 * r[i]) / 7;
        if (p <= x[i] * 100)
            cnt++;
    }
    return cnt;
}
int main()
{
    int d = 3;
    int r[d] = {3, 5, 1};
    int x[d] = {2, 2, 2};

    cout << runAroundCircle(d, r, x) << "\n";

    return 0;
}