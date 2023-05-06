#include <bits/stdc++.h>
using namespace std;

long long notInRange(long long n, int L[], int R[])
{
    sort(L, L + n);
    sort(R, R + n);
    long long m = 1000000;
    long long i = 0, sum = 0;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            sum += ((L[i] - 1) * (L[i])) / 2;
        }
        else
        {
            if (L[i] <= R[i - 1])
                L[i] = R[i - 1] + 1;
            if (L[i] != (R[i - 1] + 1))
                sum += ((L[i] - R[i - 1] - 1) * (L[i] + R[i - 1])) / 2;
        }
    }
    sum += ((m - R[i - 1]) * (m + R[i - 1] + 1)) / 2;
    return sum;
}
int main()
{

    long long n = 5;
    int L[n] = {2, 23, 21, 101, 2002};
    int R[n] = {20, 200, 21, 2000, 999998};

    cout << notInRange(n, L, R) << "\n";

    return 0;
}