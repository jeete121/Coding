#include <bits/stdc++.h>
using namespace std;

int microArrayUpdate(int n, int k, int a[])
{
    sort(a, a + n);
    if (k - a[0] < 0)
        return 0;
    else
        return k - a[0];
}
int main()
{

    int n = 3, k = 4;

    int a[n] = {1, 2, 5};

    cout << microArrayUpdate(n, k, a) << "\n";
    return 0;
}