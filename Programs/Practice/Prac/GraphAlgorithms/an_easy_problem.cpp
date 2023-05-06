#include <bits/stdc++.h>
using namespace std;

int displayTime(int x, string s)
{
    string hh = "", mm = "";
    hh += s[0];
    hh += s[1];
    mm += s[3];
    mm += s[4];

    int sum = 0;
    sum += hh[0] - '0';
    sum += hh[1] - '0';
    sum += mm[0] - '0';
    sum += mm[1] - '0';
    int cnt = 0;
    stringstream str(mm), str1(hh);
    int y = 0, z = 0;
    str >> y;
    str1 >> z;
    while (true)
    {
        if (sum % x == 0)
            break;
        cnt++;
        if (y == 59 && z == 23)
        {
            z = 0;
            y = 0;
            sum = 0;
        }
        else if (y == 59)
        {
            sum -= 14;
            y = 0;
            int q = z;
            while (q)
            {
                sum -= q % 10;
                q = q / 10;
            }
            z += 1;
            int p = z;
            while (p)
            {
                sum += p % 10;
                p = p / 10;
            }
        }
        else
        {
            int p = y;
            while (p)
            {
                sum -= p % 10;
                p = p / 10;
            }
            y += 1;
            int q = y;
            while (q)
            {
                sum += q % 10;
                q = q / 10;
            }
        }
    }
    return cnt;
}
int main()
{
    string s = "04:04";
    int x = 5;

    cout << displayTime(x, s) << "\n";
    return 0;
}