#include <bits/stdc++.h>
using namespace std;

string convertToBase7(int num)
{
    string res = "";
    if (num == 0)
        return "0";
    int flag = 0;
    if (num < 0)
        flag = 1;
    num = abs(num);
    while (num > 0)
    {
        int rem = num % 7;
        num = num / 7;
        res += ('0' + rem);
    }
    if (flag)
        res += "-";
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int num = 100;

    cout << convertToBase7(num);

    return 0;
}