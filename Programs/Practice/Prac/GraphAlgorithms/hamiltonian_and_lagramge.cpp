#include <bits/stdc++.h>
using namespace std;

void hamiltonianAndLagrangian(int n, int a[])
{
    vector<int> v;
    int max1 = a[n - 1];
    v.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= max1)
        {
            v.push_back(a[i]);
            max1 = max(max1, a[i]);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
}
int main()
{
    int n = 6;

    int a[n] = {16, 17, 4, 3, 5, 2};

    hamiltonianAndLagrangian(n, a);

    return 0;
}