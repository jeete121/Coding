#include <bits/stdc++.h>
using namespace std;

void twoArrays(int n, int a[], int b[])
{
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
        if (a[i] < 0)
            cnt1++;
    }
    for (int i = 0; i < n; i++)
    {

        sum2 += b[i];
        if (b[i] < 0)
            cnt2++;
    }

    if (sum1 != sum2)
    {
        if (sum1 > sum2 && cnt1 == 1 && cnt2 == 0)
            cout << "0\n";
        else if (sum2 > sum1 && cnt2 == 1 && cnt1 == 0)
            cout << "0\n";
        else if (sum1 > sum2 && cnt1 > 0 && cnt2 == 0)
            cout << "0\n";
        else if (sum2 > sum1 && cnt2 > 0 && cnt1 == 0)
            cout << "0\n";
        else if ((cnt1 == 0 && cnt2 == 2) || cnt1 == 2 && cnt2 == 0)
            cout << abs(sum1 - sum2) - 1 << "\n";
        else if (cnt1 == cnt2)
            cout << "Infinite\n";

        else
            cout << 1 << "\n";
    }
    else if ((cnt1 == 0 && cnt2 == 1) || (cnt1 == 1 && cnt2 == 0))
        cout << 0 << "\n";
    else
        cout << "Infinite\n";
}
int main()
{
    int n = 4;

    int a[n] = {1, 2, -1, 4};
    int b[n] = {3, 3, 3, 1};

    twoArrays(n, a, b);
    return 0;
}