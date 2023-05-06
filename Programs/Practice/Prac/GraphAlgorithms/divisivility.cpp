#include <bits/stdc++.h>
using namespace std;

bool divisibility(int n, int a[])
{
    if (a[n - 1] % 10 == 0)
        return true;
    return false;
}
int main()
{
    int n = 5;
    int a[n] = {85, 25, 65, 21, 84};

    if (divisibility(n, a))
        cout << "Yes\n";
    else
        cout << "No\n";
}