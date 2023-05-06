#include <bits/stdc++.h>
using namespace std;

long long divideNumber(long long n)
{
    vector<long long> v;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    long long flag = 0;
    sort(v.begin(), v.end());
    long long max1 = INT_MIN;
    for (long long i = 0; i < v.size(); i++)
    {
        for (long long j = i; j < v.size(); j++)
        {
            for (long long k = j; k < v.size(); k++)
            {
                long long y = n - v[i] - v[j] - v[k];
                if (y <= 0)
                    break;
                if (n % y == 0)
                {
                    max1 = max(max1, v[i] * v[j] * v[k] * y);
                    flag = 1;
                }
            }
        }
    }
    if (flag == 1)
        return max1;
    else
        return -1;
}
int main()
{

    long long n = 8;

    cout << divideNumber(n) << "\n";

    return 0;
}