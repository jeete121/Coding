#include <bits/stdc++.h>
using namespace std;

void birthdayParty(long long n, long long m)
{

    if (m % n == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    long long n = 3, m = 21;

    birthdayParty(n, m);

    return 0;
}