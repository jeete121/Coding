#include <bits/stdc++.h>
using namespace std;

bool hackMoney(long long n)
{

    if (n == 1)
        return true;
    if (n == 0)
        return false;
    if (n % 20 == 0)
        return hackMoney(n / 20) || hackMoney(n / 10);
    else if (n % 10 == 0)
        return hackMoney(n / 10);
    return false;
}
int main()
{

    long long n = 10;

    bool ans = hackMoney(n);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}