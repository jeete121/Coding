#include <bits/stdc++.h>
using namespace std;

void manasFirstName(string s)
{

    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    string str = "SUVO", str1 = "SUVOJIT";

    for (int i = 0; i <= n - 4; i++)
    {
        int flag = 0;
        if (n - i >= 7)
        {
            for (int j = 0; j < 7; j++)
            {
                if (s[i + j] != str1[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cnt2++;
            }
            else if (flag == 1)
            {
                int flag = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (s[i + j] != str[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cnt1++;
                }
            }
        }
        else
        {
            int flag = 0;
            for (int j = 0; j < 4; j++)
                if (s[i + j] != str[j])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
            {
                cnt1++;
            }
        }
    }
    cout << "SUVO = " << cnt1 << ", "
         << "SUVOJIT = " << cnt2 << "\n";
}
int main()
{
    string s = "$$$$$SUVOSUVOJIT$$$$$";

    manasFirstName(s);

    return 0;
}