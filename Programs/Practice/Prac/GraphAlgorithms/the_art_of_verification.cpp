#include <bits/stdc++.h>
using namespace std;

int search(string s, string pat)
{
    int n = s.size();
    int m = pat.size();
    int i, j;
    for (i = 0; i <= n - m; i++)
    {
        int flag = 0;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != pat[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i + j + 1;
    }
    return -1;
}
int main()
{
    string s = "http://www.cleartrip.com/signin/service?username=test&pwd=test&profile=developer&role=ELITE&key=manager";

    int n = s.size();
    int f1 = search(s, "username");
    int f2 = search(s, "pwd");
    int f3 = search(s, "profile");
    int f4 = search(s, "role");
    int f5 = search(s, "key");
    int i = f1;
    string username = "";
    int flag = 1;
    while (i < n && flag == 1)
    {
        if (s[i] == '&')
        {
            string str = "";
            for (int j = i + 1;; j++)
            {
                str += s[j];
                if (str.size() == 3)
                    break;
            }
            if (str == "pwd")
            {
                flag = 0;
                break;
            }
        }
        username += s[i];
        i++;
    }

    i = f2;
    string pwd = "";
    flag = 1;
    while (i < n && flag == 1)
    {
        if (s[i] == '&')
        {
            string str = "";
            for (int j = i + 1;; j++)
            {
                str += s[j];
                if (str.size() == 7)
                    break;
            }
            if (str == "profile")
            {
                flag = 0;
                break;
            }
        }
        pwd += s[i];
        i++;
    }
    i = f3;
    string profile = "";
    flag = 1;
    while (i < n && flag == 1)
    {
        if (s[i] == '&')
        {
            string str = "";
            for (int j = i + 1;; j++)
            {
                str += s[j];
                if (str.size() == 4)
                    break;
            }
            if (str == "role")
            {
                flag = 0;
                break;
            }
        }
        profile += s[i];
        i++;
    }
    i = f4;
    string role = "";
    flag = 1;
    while (i < n && flag == 1)
    {
        if (s[i] == '&')
        {
            string str = "";
            for (int j = i + 1;; j++)
            {
                str += s[j];
                if (str.size() == 3)
                    break;
            }
            if (str == "key")
            {
                flag = 0;
                break;
            }
        }
        role += s[i];
        i++;
    }
    i = f5;
    string key = "";
    while (i < n)
    {
        key += s[i];
        i++;
    }
    cout << "username: " << username << "\n";
    cout << "pwd: " << pwd << "\n";
    cout << "profile: " << profile << "\n";
    cout << "role: " << role << "\n";
    cout << "key: " << key << "\n";
    return 0;
}