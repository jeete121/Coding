#include <iostream>
using namespace std;

long long simpleSearch(long long n,
                       long long a[], long long k)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            j = i;
    }
    return j;
}
int main()
{
    long long n = 5;
    long long a[n] = {1, 2, 3, 4, 5};
    long long k = 4;

    cout << simpleSearch(n, a, k) << "\n";

    return 0;
}