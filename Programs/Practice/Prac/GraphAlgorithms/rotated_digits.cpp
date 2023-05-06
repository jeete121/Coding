#include <bits/stdc++.h>
using namespace std;

int rotatedDigits(int N)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int j = i;
        string str = "";
        int flag = 0;
        while (j > 0)
        {
            if (j % 10 == 3 || j % 10 == 4 || j % 10 == 7)
            {
                flag = 1;
                break;
            }
            else if (j % 10 == 2)
                str += "5";
            else if (j % 10 == 5)
                str += "2";
            else if (j % 10 == 6)
                str += "9";
            else if (j % 10 == 9)
                str += "6";
            else
                str += to_string(j % 10);
            j = j / 10;
        }
        reverse(str.begin(), str.end());
        if (flag == 0 && str != to_string(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int n = 10;
    cout << rotatedDigits(n);
    return 0;
}