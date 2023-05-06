#include <bits/stdc++.h>
using namespace std;

int alternatingCharacters(string s)
{
    int res = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if ((s[i] == 'A' && s[i + 1] == 'A') || 
              (s[i] == 'B' && s[i + 1] == 'B'))
            res++;
    }
    return res;
}

int main()
{
    string s = "AAABBB";
    int result = alternatingCharacters(s);

    cout << result << "\n";

    return 0;
}
