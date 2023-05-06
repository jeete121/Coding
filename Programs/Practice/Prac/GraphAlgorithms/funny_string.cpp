#include <bits/stdc++.h>
using namespace std;

string funnyString(string s)
{
    vector<int> res;
    string s2 = "";
    for (int i = s.size() - 1; i >= 0; i--)
        s2 += s[i];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (abs(s[i] - s[i + 1]) != abs(s2[i] - s2[i + 1]))
            return "Not Funny";
    }
    return "Funny";
}

int main()
{

    string s = "acxz";
    string result = funnyString(s);

    cout << result << "\n";

    return 0;
}
