#include <bits/stdc++.h>
using namespace std;

bool binaryAssociativity(char c0, char c1, char c2, char c3)
{
    map<string, char> mp;
    mp["00"] = c0;
    mp["01"] = c1;
    mp["10"] = c2;
    mp["11"] = c3;
    string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "", s6 = "", s7 = "", s8 = "";
    string s9 = "", s10 = "", s11 = "", s12 = "", s13 = "", s14 = "", s15 = "", s16 = "";
    s1 += c0;
    s1 += '0';
    s2 += '0';
    s2 += c0;
    s3 += c0;
    s3 += '1';
    s4 += '0';
    s4 += c1;
    s5 += c1;
    s5 += '0';
    s6 += '0';
    s6 += c2;
    s7 += c1;
    s7 += '1';
    s8 += '0';
    s8 += c3;
    s9 += c2;
    s9 += '0';
    s10 += '1';
    s10 += c0;
    s11 += c2;
    s11 += '1';
    s12 += '1';
    s12 += c1;
    s13 += c3;
    s13 += '0';
    s14 += '1';
    s14 += c2;
    s15 += c3;
    s15 += '1';
    s16 += '1';
    s16 += c3;
    if (mp[s1] != mp[s2] || mp[s3] != mp[s4] || mp[s5] != mp[s6] || mp[s7] != mp[s8] || mp[s9] != mp[s10] || mp[s11] != mp[s12] || mp[s13] != mp[s14] || mp[s15] != mp[s16])
        return false;
    else
        return true;
}
int main()
{

    char c0 = '0', c1 = '1', c2 = '1', c3 = '0';

    if (binaryAssociativity(c0, c1, c2, c3))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}