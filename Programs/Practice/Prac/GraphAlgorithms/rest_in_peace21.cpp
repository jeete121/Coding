#include <bits/stdc++.h>
using namespace std;

void restInPeace(int n)
{
    if (n % 21 == 0)
        cout << "The streak is broken!\n";
    else
    {
        string s = to_string(n);
        int i = 0;
        int flag = 0;
        while (i < (int)s.size() - 1)
        {
            if (s[i] == '2' && s[i + 1] == '1')
            {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag)
            cout << "The streak is broken!\n";
        else
            cout << "The streak lives still in our heart!\n";
    }
}
int main()
{

    int n = 120;

    restInPeace(n);

    return 0;
}