#include <bits/stdc++.h>
using namespace std;

void finalDestination(string s)
{
    int L = 0, R = 0, U = 0, D = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            L++;
        else if (s[i] == 'R')
            R++;
        else if (s[i] == 'U')
            U++;
        else
            D++;
    }
    cout << R - L << " " << U - D << "\n";
}
int main()
{
    string s = "LLRDDR";

    finalDestination(s);

    return 0;
}