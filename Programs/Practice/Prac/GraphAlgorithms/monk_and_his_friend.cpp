#include <bits/stdc++.h>
using namespace std;

long long monkAndFriend(long long a, long long b)
{
    long long res = 0;
    while (a || b)
    {
        if (a % 2 == 0 && b % 2 != 0)
            res++;
        else if (a % 2 != 0 && b % 2 == 0)
            res++;
        a = a / 2;
        b = b / 2;
    }
    return res;
}
int main()
{

    long long a = 1, b = 4;

    long long ans = monkAndFriend(a, b);
    cout << ans << "\n";

    return 0;
}