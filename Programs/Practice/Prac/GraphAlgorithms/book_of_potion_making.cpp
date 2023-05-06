#include <bits/stdc++.h>
using namespace std;

void potionMaking(long long n)
{
    int res = 0, cnt = 0;
    int i = 10;
    while (n)
    {
        int x = n % 10;
        res += x * i;
        n = n / 10;
        i--;
        cnt++;
    }
    if (cnt < 10)
        cout << "Illegal ISBN\n";
    else if (res % 11 == 0)
        cout << "Legal ISBN\n";
    else
        cout << "Illegal ISBN\n";
}
int main()
{
    long long n = 1401601499;

    potionMaking(n);

    return 0;
}