#include <bits/stdc++.h>
using namespace std;

int finalCardNumber(int n)
{
    int p = 1;
    while (n != 1)
    {
        if (pow(2, p) > n)
            break;
        p += 1;
    }
    p = p - 1;
    if (pow(2, p) == n)
        return n;
    else
        return ((n - pow(2, p)) * 2);
}
int main()
{

    int n = 5;

    cout << finalCardNumber(n) << "\n";

    return 0;
}