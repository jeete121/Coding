#include <bits/stdc++.h>
using namespace std;

string generateTheString(int n)
{
    string res = "";
    if (n & 1)
    {
        for (int i = 0; i < n; i++)
            res += "a";
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            res += "a";
        res += "b";
    }
    return res;
}

int main()
{
    int n = 4;
    cout << generateTheString(n);
    return 0;
}