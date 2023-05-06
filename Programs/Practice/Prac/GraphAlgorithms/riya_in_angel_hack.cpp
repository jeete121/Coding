#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 6;

    if (n % 3 == 0 && n % 5 == 0)
        cout << "AngelHack!\n";
    else if (n % 3 == 0)
        cout << "Angel\n";
    else if (n % 5 == 0)
        cout << "Hack\n";
    else
        cout << n << "\n";
    return 0;
}