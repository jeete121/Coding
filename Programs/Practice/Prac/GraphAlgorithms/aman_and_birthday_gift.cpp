#include <bits/stdc++.h>
using namespace std;

void birthdayGift(int a, int b, int c)
{
    if (b > a && c <= 0)
        cout << "NO\n";
    else if (b > a)
    {
        int flag = 0;
        while (b > a)
        {
            a = a + c;
            if (a == b)
            {
                flag = 1;
                break;
            }
            else if (a > b)
                break;
        }
        if (flag == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        if (c >= 0)
            cout << "NO\n";
        else
        {
            int flag = 0;
            while (a > b)
            {
                a = a + c;
                if (b == a)
                {
                    flag = 1;
                    break;
                }
                else if (a < b)
                    break;
            }
            if (flag == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
int main()
{
    int a = 1, b = 7, c = 3;

    birthdayGift(a, b, c);
    return 0;
}