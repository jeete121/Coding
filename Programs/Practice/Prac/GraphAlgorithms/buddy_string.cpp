#include <bits/stdc++.h>
using namespace std;

bool buddyStrings(string A, string B)
{
    int n = A.size();
    int m = B.size();
    if (n != m)
        return false;
    int i = 0;
    char c, d;
    for (i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            c = B[i];
            d = A[i];
            break;
        }
    }
    if (i == n)
    {
        int f[26] = {0};
        for (int k = 0; k < n; k++)
            f[A[k] - 'a']++;
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (f[i] >= 2)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return false;
        return true;
    }
    else
    {
        int k;
        int flag1 = 0;
        for (k = i + 1; k < n; k++)
        {
            if (A[k] != B[k])
            {
                if (A[k] == c && B[k] == d)
                {
                    flag1 = 1;
                    break;
                }
            }
        }
        int flag = 0;
        for (int l = k + 1; l < n; l++)
        {
            if (A[l] != B[l])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && flag1 == 1)
            return true;
        return false;
    }
}

int main()
{
    string A = "ab", B = "ba";
    if (buddyStrings(A, B))
        cout << "true";
    else
        cout << "false";

    return 0;
}