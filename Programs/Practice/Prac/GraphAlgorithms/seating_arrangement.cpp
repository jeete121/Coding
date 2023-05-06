#include <bits/stdc++.h>
using namespace std;
int main()
{

    map<int, int> mp;
    int i = 1, j = 12;
    int m = i + 11, o = j + 11;
    int cnt = 1;
    while (cnt <= 9 && j > i)
    {
        mp[i] = j;
        mp[j] = i;
        i++;
        j--;
        if (i > j)
        {
            i = m + 1;
            m = m + 12;
            j = o + 1;
            o = o + 12;
            cnt++;
        }
    }

    map<int, string> mp1;
    mp1[1] = "WS";
    for (int j = 12; j <= 108; j += 11)
    {
        mp1[j] = "WS";
        j++;
        if (j <= 108)
            mp1[j] = "WS";
    }
    for (int j = 6; j <= 108; j += 11)
    {
        mp1[j] = "WS";
        j++;
        if (j <= 108)
            mp1[j] = "WS";
    }
    mp1[2] = "MS";
    for (int j = 11; j <= 108; j += 9)
    {
        mp1[j] = "MS";
        j += 3;
        if (j <= 108)
            mp1[j] = "MS";
    }
    for (int j = 5; j <= 108; j += 9)
    {
        mp1[j] = "MS";
        j += 3;
        if (j <= 108)
            mp1[j] = "MS";
    }
    mp1[3] = "AS";
    for (int j = 10; j <= 108; j += 7)
    {
        mp1[j] = "AS";
        j += 5;
        if (j <= 108)
            mp1[j] = "AS";
    }
    for (int j = 4; j <= 108; j += 7)
    {
        mp1[j] = "AS";
        j += 5;
        if (j <= 108)
            mp1[j] = "AS";
    }

    int n = 18;

    cout << mp[n] << " " << mp1[n] << "\n";

    return 0;
}