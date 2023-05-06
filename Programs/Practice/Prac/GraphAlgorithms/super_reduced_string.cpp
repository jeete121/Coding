#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s)
{
    while (true)
    {
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                i = i + 2;
            }
        }
        if (s.size() == 0)
            break;
        else
        {
            int i = 0;
            while (i < s.size() - 1)
            {
                if (s[i] != s[i + 1])
                    i++;
                else
                    break;
            }
            if (i == s.size() - 1)
                break;
        }
    }
    if (s.size() == 0)
        return "Empty String";
    return s;
}

int main()
{
    string s = "aaabccddd";
    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}
