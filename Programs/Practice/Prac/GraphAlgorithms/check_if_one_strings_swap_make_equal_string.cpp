#include <bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2)
{

    int n = s1.size();

    int i = 0, j = n - 1;

    while (i < j)
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    while (i < j)
    {
        if (s1[j] == s2[j])
        {
            j--;
        }
        else
        {
            break;
        }
    }

    if (s2[i] == s1[j] && s2[j] == s1[i])
        swap(s2[i], s2[j]);
    else
        return false;

    while (i < j)
    {
        if (s1[i] != s2[i])
            return false;
        else
            i++;
    }
    return true;
}

int main()
{
    string s1 = "bank", s2 = "kanb";

    if (areAlmostEqual(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}