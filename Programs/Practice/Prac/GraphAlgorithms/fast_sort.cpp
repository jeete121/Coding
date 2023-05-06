#include <bits/stdc++.h>
using namespace std;

string fastSort(string p, string s)
{

    int f[26] = {0};
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a']++;
    string str = "";
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < f[p[i] - 'a']; j++)
            str += p[i];
    }
    return str;
}
int main()
{
    string p = "wcyuogmlrdfphitxjakqvzbnes";
    string s = "jcdokai";

    cout << fastSort(p, s) << "\n";

    return 0;
}