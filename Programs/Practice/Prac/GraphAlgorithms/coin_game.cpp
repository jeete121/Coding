#include <bits/stdc++.h>
using namespace std;

void coinGame(int n, int a[])
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x % 2 == 0)
        {
            cnt++;
            x = x / 2;
        }
    }
    if (cnt & 1)
        cout << "Charlie\n";
    else
        cout << "Alan\n";
}
int main()
{

    int n = 3;
    int a[n] = {2, 4, 2};

    coinGame(n, a);

    return 0;
}