#include <bits/stdc++.h>
using namespace std;

long long appleDivision(long long arr[], long long i,
                        long long sumcal, long long sum)
{
    if (i == 0)
        return abs((sum - sumcal) - sumcal);
    return min(appleDivision(arr, i - 1, sumcal + arr[i - 1], sum),
               appleDivision(arr, i - 1, sumcal, sum));
}
int main()
{
    long long n = 5;

    long long arr[n] = {3, 2, 7, 4, 1};
    long long sum = 0;

    for (long long  i = 0; i < n; i++)
        sum += arr[i];
    cout << appleDivision(arr, n, 0, sum) << "\n";
    return 0;
}