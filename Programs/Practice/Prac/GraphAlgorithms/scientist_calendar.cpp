#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    if ((n % 400 == 0 || n % 100 != 0) && (n % 4 == 0))
        return 2;
    return 1;
}

int scienCalendar(int n)
{
    int day = count(n);
    int m = n + 1;
    int sum = 0;
    int ans = m;
    while (true)
    {
        sum = (sum + count(m)) % 7;
        if (sum == 0 && day == count(m))
        {
            ans = m;
            break;
        }
        m++;
    }
    return ans;
}
int main()
{
    int n = 2005;

    cout << scienCalendar(n) << "\n";

    return 0;
}