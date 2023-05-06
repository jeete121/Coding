#include <bits/stdc++.h>
using namespace std;

bool prime[1001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
                prime[j] = false;
        }
    }
}
string primeString(string s)
{

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int len = s[i];
        if (len < 97)
            s[i] = 'a';
        else if (prime[len] == false)
        {
            int j;
            int flag = 0, flag1 = 0;
            int x1, x2;
            for (j = len + 1; j <= 122; j++)
            {
                if (prime[j])
                {
                    flag = 1;
                    x1 = j;
                    break;
                }
            }
            int k;
            for (k = len - 1; k >= 97; k--)
            {
                if (prime[k])
                {
                    flag1 = 1;
                    x2 = k;
                    break;
                }
            }
            if (flag == 1 && flag1 == 1)
            {

                if (x1 - len < len - x2)
                    s[i] = x1;
                else
                    s[i] = x2;
            }
            else if (flag1 == 1 && flag == 0)
                s[i] = x2;
            else if (flag == 1 && flag1 == 0)
                s[i] = x1;
        }
    }
    return s;
}
int main()
{
    primeInitialize();
    string s = "abcd";

    cout << primeString(s) << "\n";

    return 0;
}