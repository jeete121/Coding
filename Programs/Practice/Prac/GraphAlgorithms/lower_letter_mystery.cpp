#include <bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string s)
{
    int n = s.size();
    int i = 0, j = n - 1, cnt = 0;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (s[i] > s[j])
            {
                cnt += s[i] - s[j];
                s[i] = s[j];
                i++;
                j--;
            }
            else
            {
                cnt += s[j] - s[i];
                s[j] = s[i];
                i++;
                j--;
            }
        }
    }
    return cnt;
}

int main()
{

    string s = "abc";

    int result = theLoveLetterMystery(s);

    cout << result << "\n";

    return 0;
}
