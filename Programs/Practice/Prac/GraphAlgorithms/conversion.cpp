#include <bits/stdc++.h>
using namespace std;

string conversion(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z')
            res += to_string(s[i] - 'a' + 1);
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            res += to_string(s[i] - 'A' + 1);
        }
        else
            res += '$';
    }
    return res;
}
int main()
{

    string s = "AMbuj verma";

    cout << conversion(s) << "\n";

    return 0;
}