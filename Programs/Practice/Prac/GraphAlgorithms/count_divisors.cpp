#include <bits/stdc++.h>
using namespace std;

int countDivisors(int l, int r, int k)
{

    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (i % k == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    int l = 1, r = 10, k = 1;

    cout << countDivisors(l, r, k) << "\n";

    return 0;
}