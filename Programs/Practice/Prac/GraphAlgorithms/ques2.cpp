#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5, x = 1, y = 5;

    int a[n] = {1, 2, 3, 4, 5};

    sort(a, a + n);
    if (a[0] >= x && a[n - 1] <= y)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}