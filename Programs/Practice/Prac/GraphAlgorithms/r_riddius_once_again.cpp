#include <bits/stdc++.h>
using namespace std;

void shiftDNumbers(int n, int d, int a[])
{

    int f[d];
    for (int i = 0; i < d; i++)
        f[i] = a[i];
    int l = 0;
    for (int i = d; i < n; i++)
        a[l++] = a[i];
    for (int i = 0; i < d; i++)
        a[l++] = f[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int n = 5, d = 4;

    d = d % n;
    int a[n] = {1, 2, 3, 4, 5};

    shiftDNumbers(n, d, a);
    return 0;
}