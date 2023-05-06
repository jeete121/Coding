#include <bits/stdc++.h>
using namespace std;

int coutVowels(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u')
            cnt++;
    }
    return cnt;
}
int main()
{

    string s = "hashes";

    cout << coutVowels(s) << "\n";

    return 0;
}