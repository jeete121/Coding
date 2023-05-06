#include <bits/stdc++.h>
using namespace std;

string toBinary(int n)
{
    string res = "";
    while (n > 0)
    {
        if (n % 2 == 0)
            res = '0' + res;
        else
            res = '1' + res;
        n = n / 2;
    }
    return res;
}
bool hasAlternatingBits(int n)
{
    string str = toBinary(n);
    int len = str.size();

    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == '0' && str[i + 1] == '0')
            return false;
        else if (str[i] == '1' && str[i + 1] == '1')
            return false;
    }
    return true;
}
int main()
{
    int n = 5;

    if (hasAlternatingBits(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}