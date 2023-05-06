#include <bits/stdc++.h>
using namespace std;

long long powerOfTwo(long long n, long long arr[])
{
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x = arr[i];

        long long flag = 0;
        while (x != 1)
        {
            if (x & 1)
            {
                flag = 1;
                break;
            }
            x = x / 2;
        }
        if (flag == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    long long n = 5;

    long long arr[] = {1, 2, 3, 4, 5};

    cout << powerOfTwo(n, arr) << "\n";

    return 0;
}