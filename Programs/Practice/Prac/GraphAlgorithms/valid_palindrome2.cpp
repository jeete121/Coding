#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    string str = "", str1 = "";
    vector<char> v;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            str += s[i];
            v.push_back(s[j]);
            str1 += s[i];
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    for (int l = i; l < j; l++)
        str += s[l];
    for (int l = v.size() - 1; l >= 0; l--)
        str += v[l];
    for (int l = i + 1; l <= j; l++)
        str1 += s[l];
    for (int l = v.size() - 1; l >= 0; l--)
        str1 += v[l];
    int len = str.size(), len1 = str1.size();
    flag = 0;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    flag = 0;
    for (int i = 0; i < len1 / 2; i++)
    {
        if (str1[i] != str1[len1 - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    return false;
}

int main()
{
    string str = "abca";
    if (validPalindrome(str))
        cout << "true";
    else
        cout << "false";
    return 0;
}