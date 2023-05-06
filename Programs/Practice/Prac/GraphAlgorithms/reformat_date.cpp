#include <bits/stdc++.h>
using namespace std;

//function to reformat the given date
string reformatDate(string s)
{
    int n = s.size();
    int i = 0;
    string str = "";
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        str += s[i];
        i++;
    }
    while (s[i] != ' ')
        i++;
    i++;
    string str1 = "";
    int k = i;
    for (int j = k; j < k + 3; j++)
    {
        str1 += s[j];
        i++;
    }
    while (s[i] == ' ')
        i++;
    int cnt = 0;
    string str2 = "";
    while (i < n)
    {
        str2 += s[i];
        i++;
        cnt++;
        if (cnt == 4)
            break;
    }
    string res = "";
    for (int i = 0; i < str2.size(); i++)
        res += str2[i];
    res += '-';
    map<string, string> mp;
    mp["Jan"] = "01";
    mp["Feb"] = "02";
    mp["Mar"] = "03";
    mp["Apr"] = "04";
    mp["May"] = "05";
    mp["Jun"] = "06";
    mp["Jul"] = "07";
    mp["Aug"] = "08";
    mp["Sep"] = "09";
    mp["Oct"] = "10";
    mp["Nov"] = "11";
    mp["Dec"] = "12";
    res += mp[str1];
    res += '-';
    if (str.size() == 1)
    {
        res += "0";
        res += str[0];
    }
    else
    {
        res += str[0];
        res += str[1];
    }
    return res;
}

int main()
{
    string date = "20th Oct 2052";
    cout << reformatDate(date);
    return 0;
}