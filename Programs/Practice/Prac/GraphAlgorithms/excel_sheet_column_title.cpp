#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int n)
{
    string res = "";
    while (n > 0)
    {
        int rem = n % 26;
        if (rem == 0)
        {
            res += 'Z';
            n = (n / 26) - 1;
        }
        else
        {
            res += rem - 1 + 'A';
            n = n / 26;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n = 701;
    cout << convertToTitle(n);

    return 0;
}