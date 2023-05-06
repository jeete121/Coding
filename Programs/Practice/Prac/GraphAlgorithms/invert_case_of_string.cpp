#include <bits/stdc++.h>
using namespace std;

string invertCaseOfCharacters(string s, int n1, int n2)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 == n1 || i + 1 == n2 && s[i] != ' ')
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
            else if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
        }
    }
    return s;
}
int main()
{
    string s = "Jamia Hamdard";

    int n1 = 2, n2 = 9;

    cout << invertCaseOfCharacters(s, n1, n2) << "\n";

    return 0;
}