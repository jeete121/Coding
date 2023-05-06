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

string magicalWord(int n, string s)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= 65)
            s[i] = 'C';
        else
        {
            int x = s[i];
            if (!isprime(x))
            {
                int x1 = x, x2 = x, res;
                int flag = 0, flag1 = 0;
                for (int j = x - 1; j >= 65; j--)
                {
                    if (isprime(j))
                    {
                        x1 = j;
                        flag = 1;
                        break;
                    }
                }
                for (int j = x + 1; j <= 122; j++)
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
                    if (abs(x2 - x) < abs(x - x1))
                        res = x2;
                    else
                        res = x1;
                }
                else if (flag == 1)
                    res = x1;
                else
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

    int n = 6;
    string s = "AFREEN";
    cout << magicalWord(n, s) << "\n";

    return 0;
}