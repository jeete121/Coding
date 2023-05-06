#include <bits/stdc++.h>
using namespace std;

void aliceStrings(string A, string B)
{
    if (A.size() != B.size())
        cout << "NO\n";
    else if (A == B)
        cout << "YES\n";
    else
    {
        int i = A.size() - 1;
        while (i > 0 && A[i] == B[i])
        {
            i--;
        }
        int p = B[i] - A[i];

        int flag = 0;
        for (int j = i; j >= 0; j--)
        {
            if ((B[j] - A[j]) != p)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    string A = "abaca", B = "cdbda";

    aliceStrings(A, B);

    return 0;
}