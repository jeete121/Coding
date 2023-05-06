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

string nameGame(int n, string s)
{

    for (int i = 0; i < n; i++)
    {
        int x = s[i];
        if (x < 65)
            s[i] = 'C';
        else
        {
            if (!isprime(x))
            {
                int flag1 = 0, flag = 0, x1, x2, res;
                for (int j = x + 1; j <= 122; j++)
                {
                    if (isprime(j))
                    {
                        x1 = j;
                        flag = 1;
                        break;
                    }
                }
                for (int j = x - 1; j >= 65; j--)
                {
                    if (isprime(j))
                    {
                        x2 = j;
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 1 && flag == 1)
                {
                    if (x - x2 <= x1 - x)
                        res = x2;
                    else
                        res = x1;
                }
                else if (flag == 1)
                    res = x1;
                else if (flag1 == 1)
                    res = x2;
                char c = res;
                s[i] = c;
            }
        }
    }
    return s;
}
int main()
{

    int n = 8;
    string s = "KINGKONG";

    cout << nameGame(n, s) << "\n";

    return 0;
}