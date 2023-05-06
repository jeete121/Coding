#include <bits/stdc++.h>
using namespace std;

string strings_xor(string s, string t)
{

    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[i])
            res += "0";
        else
            res += "1";
    }

    return res;
}

int main()
{
    string s = "10101", t = "00101";

    cout << strings_xor(s, t) << endl;
    return 0;
}
