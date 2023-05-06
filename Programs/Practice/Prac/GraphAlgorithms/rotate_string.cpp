#include <bits/stdc++.h>
using namespace std;

bool rotateString(string A, string B)
{
    int n = A.size();
    int m = B.size();
    if (n != m)
        return false;
    if (A == B)
        return true;
    int t = n;
    while (t--)
    {
        string x = "";
        char temp = A[0];
        for (int i = 1; i < n; i++)
            x += A[i];
        x += temp;
        A = x;
        if (A == B)
            return true;
    }
    return false;
}

int main()
{
    string A = "abcde";
    string B = "cdeab";

    if (rotateString(A, B))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}