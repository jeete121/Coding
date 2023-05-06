#include <bits/stdc++.h>
using namespace std;

bool consonent(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    return true;
}

string compressString(int n, string s)
{

    int i = 1;
    string res = "";
    if (s[0] >= 'a' && s[0] <= 'z')
        res += s[0] - 32;
    else
        res += s[0];
    while (i < n)
    {

        if (consonent(s[i]) == false)
        {
            while (i < n - 1 && s[i] == s[i + 1])
                i++;
            res += s[i];
            i++;
        }
        else
        {
            int cnt = 0;
            while (i < n && consonent(s[i]))
            {
                cnt++;
                i++;
            }
            ostringstream str1;
            str1 << cnt;
            string strin = str1.str();

            res += strin;
        }
    }
    return res;
}
int main()
{
    int n = 10;
    string s = "aaabcdefee";

    cout << compressString(n, s) << "\n";

    return 0;
}