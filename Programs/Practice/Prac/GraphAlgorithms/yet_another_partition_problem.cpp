#include <bits/stdc++.h>
using namespace std;

int partition(int n, int a[])
{

    int x = 0;
    for (int i = 0; i < n; i++)
        x = x ^ a[i];
    int y = 0, z = 0, max1 = x;
    for (int i = 0; i < n; i++)
    {
        //parition at ith position
        y = y ^ a[i];
        z = y & (y ^ x);
        if (z > max1)
            max1 = z;
    }
    return max1;
}
int main()
{

    int n = 7;
    int a[n] = {4, 1, 2, 5, 2, 1, 6};

    cout << partition(n, a) << "\n";
    return 0;
}