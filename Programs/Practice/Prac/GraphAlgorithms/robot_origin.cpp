#include <bits/stdc++.h>
using namespace std;

bool judgeCircle(string s)
{
    int n = s.size();
    int L = 0, R = 0, U = 0, D = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            L++;
        else if (s[i] == 'R')
            R++;
        else if (s[i] == 'U')
            U++;
        else if (s[i] == 'D')
            D++;
    }
    int x = U - D, y = R - L;
    if (x == 0 && y == 0)
        return true;
    return false;
}
int main()
{
    string moves = "UD";
    if (judgeCircle(moves))
        cout << "true";
    else
        cout << "false";

    return 0;
}