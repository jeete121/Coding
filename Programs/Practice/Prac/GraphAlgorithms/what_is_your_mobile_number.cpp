#include <bits/stdc++.h>
using namespace std;

void checkMobileNumber(string s)
{
    if (s.size() != 10)
        cout << "NO\n";
    else
    {
        if (s[0] != '0' && s[0] >= '1' && s[0] <= '9')
        {
            long long i = 1, flag = 0;
            while (i < 10)
            {
                if (s[i] >= '0' && s[i] <= '9')
                    i++;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}
int main()
{

    string s = "1234567890";

    checkMobileNumber(s);

    return 0;
}