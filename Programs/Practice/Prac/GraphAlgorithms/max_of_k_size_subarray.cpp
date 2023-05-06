#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 9, k = 3;

    long long a[n] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    for (long long i = 0; i <= n - k; i++)
        cout << *max_element(a + i, a + i + k) << " ";
    cout << "\n";
}
