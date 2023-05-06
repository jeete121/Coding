#include <bits/stdc++.h>
using namespace std;

int majorityAndCity(int n, int a[])
{
    int max1 = INT_MIN, cnt = 0;
    int i = 0;
    while (i < n)
    {
        cnt = 1;
        while (i < n - 1 && a[i] == a[i + 1])
        {
            cnt++;
            i++;
        }
        i++;
        max1 = max(cnt, max1);
    }
    return max1;
}
int main()
{

    int n = 5;

    int a[n] = {0, 1, 1, 0, 1};

    cout << majorityAndCity(n, a) << "\n";

    return 0;
}
