#include <bits/stdc++.h>
using namespace std;

int repeatedKTimes(int n, int a[], int k)
{
    sort(a, a + n);

    int cnt = 1;
    int i = 0;
    int res = 0;
    while (i < n - 1)
    {
        cnt = 1;
        while (i < n - 1 && a[i] == a[i + 1])
        {
            cnt++;
            i++;
        }
        if (cnt == k)
        {
            res = a[i];
            break;
        }
        i++;
    }
    return res;
}
int main()
{
    int n = 5;

    int a[n] = {2, 2, 1, 3, 1};
    int k = 2;

    cout << repeatedKTimes(n, a, k) << "\n";

    return 0;
}