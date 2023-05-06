#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 30;

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            res += i;
        }
    }
    cout << res << "\n";

    return 0;
}