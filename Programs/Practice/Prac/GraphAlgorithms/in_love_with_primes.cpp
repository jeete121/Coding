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
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (isprime(i) && isprime(n - i))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Arjit\n";
    else
        cout << "Deepa\n";

    return 0;
}