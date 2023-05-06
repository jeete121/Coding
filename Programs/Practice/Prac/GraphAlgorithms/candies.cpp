#include <bits/stdc++.h>
using namespace std;

int candies(int n, int m, int a[])
{
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] <= 0)
            sum += abs(a[i]);
    }
    return sum;
}
int main()
{
    int n = 5, m = 3;

    int a[n] = {-6, 0, 35, -2, 4};

    cout << candies(n, m, a) << "\n";

    return 0;
}