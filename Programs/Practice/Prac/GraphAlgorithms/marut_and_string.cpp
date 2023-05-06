#include <bits/stdc++.h>
using namespace std;

void marutAndString(string s)
{
    if (s.size() > 100)
        cout << "Invalid Input\n";
    else
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                cnt1++;
            else if (s[i] >= 'a' && s[i] <= 'z')
                cnt2++;
        }
        if (cnt1 == 0 && cnt2 == 0)
            cout << "Invalid Input\n";
        else
            cout << min(cnt1, cnt2) << "\n";
    }
}
int main()
{

    string s = "abcEfg";

    marutAndString(s);

    return 0;
}