#include <bits/stdc++.h>
using namespace std;

string decodeIt(string s)
{

    int n = s.size();
    string str = "";
    int i = n - 1;
    while (true)
    {
        if (i < 0)
        {
            if (n % 2 == 0)
                i = n - 1 + i;
            else
                i = n + i;
            str += s[i];
            i = i - (1 + n) / 2;
        }
        else
        {
            str += s[i];
            i = i - (1 + n) / 2;
        }
        if (str.size() == n)
            break;
    }
    return str;
}
int main()
{

    string s = "hiolmtrga";

    cout << decodeIt(s) << "\n";

    return 0;
}