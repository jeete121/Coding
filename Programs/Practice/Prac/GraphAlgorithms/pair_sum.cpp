#include <bits/stdc++.h>
using namespace std;

bool pairSum(int n, int k, int a[])
{
    sort(a, a + n);
    int i = 0, j = n - 1, flag = 0;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            flag = 1;
            break;
        }
        else if (a[i] + a[j] > k)
            j--;
        else
            i++;
    }
    if (flag == 1)
        return true;
    else
        return false;
}
int main()
{
    int n = 5, k = 9;

    int a[n] = {1, 2, 3, 4, 5};

    if (pairSum(n, k, a))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}