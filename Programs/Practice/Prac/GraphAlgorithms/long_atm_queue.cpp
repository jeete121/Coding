#include <bits/stdc++.h>
using namespace std;

int longAtmQueue(int n, int a[])
{
    int res = 0;
    int i = 0;
    while (i < n - 1)
    {
        if (a[i] > a[i + 1])
            res++;
        i++;
    }
    return res + 1;
}
int main()
{
    int n = 4;

    int a[n] = {1, 2, 3, 4};

    cout << longAtmQueue(n, a) << "\n";

    return 0;
}