#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{

    int n = 4;

    if (n <= 2)
        cout << "No\n";
    else if (n % 2 == 0)
        cout << "Yes\n";
    else if (isprime(n))
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}