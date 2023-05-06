#include <bits/stdc++.h>
using namespace std;

int beautifulBinaryString(string s)
{
    int n = s.size();
    if (n < 3)
        return 0;
    else
    {
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0')
            {
                cnt++;
                s[i + 2] = '1';
            }
        }
        return cnt;
    }
}
int main()
{
    int n = 10;

    string s = "0100101010";
    cout << beautifulBinaryString(s);
    return 0;
}
