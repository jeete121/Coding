#include <bits/stdc++.h>
using namespace std;

void mergeTwoArrays(long long n, long long m,
                    long long a[], long long b[])
{
    vector<long long> v;
    long long i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else
        {
            v.push_back(b[j]);
            j++;
        }
    }
    while (i < n)
    {
        v.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        v.push_back(b[j]);
        j++;
    }
    for (long long i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
int main()
{

    long long n = 4, m = 5;

    long long a[n] = {9, 7, 5, 3};
    long long b[m] = {8, 6, 4, 2, 0};

    mergeTwoArrays(n, m, a, b);

    return 0;
}