#include <bits/stdc++.h>
using namespace std;

long long theOldMonk(int n, long long arr[],
                     long long brr[])
{

    long long ans = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (brr[j] >= arr[i])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
            i++;
    }
    return ans;
}
int main()
{
    int n = 9;

    long long arr[n] = {7, 7, 3, 3, 3, 2, 2, 2, 1};
    long long brr[n] = {8, 8, 7, 7, 5, 5, 4, 3, 2};

    cout << theOldMonk(n, arr, brr) << "\n";

    return 0;
}