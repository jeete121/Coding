#include <bits/stdc++.h>
using namespace std;

//function to check for prime number
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool primeString(string s)
{
    int n = s.size();
    int f[26] = {0};
    for (int i = 0; i < n; i++)
        f[s[i] - 'a']++;
    int sum = 0;
    for (int i = 0; i < 26; i++)
        if (f[i] > 0)
            sum++;
    if (isprime(sum))
    {
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (f[i] > 0)
            {
                if (!isprime(f[i]))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{

    string s = "ababb";

    if (primeString(s))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}