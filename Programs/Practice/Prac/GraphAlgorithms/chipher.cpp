#include <bits/stdc++.h>
using namespace std;

string chipher(string s, int k)
{
    int n = s.size();
    map<int, char> mp, mp1, mp3;
    for (int i = 0; i < 26; i++)
        mp[i] = i + 'A';
    for (int i = 0; i < 26; i++)
        mp1[i] = i + 'a';
    for (int i = 0; i < 10; i++)
        mp3[i] = i + '0';
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int x = (s[i] - 'A' + k) % 26;
            s[i] = mp[x];
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            int x = (s[i] - 'a' + k) % 26;
            s[i] = mp1[x];
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            int x = (s[i] - '0' + k) % 10;
            s[i] = mp3[x];
        }
    }
    return s;
}
int main()
{
    string s = "All-convoYs-9-be:Alert1.";

    int k = 4;

    cout << chipher(s, k) << "\n";

    return 0;
}