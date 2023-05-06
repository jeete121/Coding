#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int main()
{

    string s = "www.google.com";

    int cnt = 0;
    for (int i = 4; s[i] != '.'; i++)
    {
        if (isVowel(s[i]) == false)
            cnt++;
    }
    cnt += 4;
    cout << cnt << "/" << s.size() << "\n";

    return 0;
}