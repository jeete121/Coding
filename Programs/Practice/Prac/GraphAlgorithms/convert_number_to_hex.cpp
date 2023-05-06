#include <bits/stdc++.h>
using namespace std;

string toHex(int num)
{
    if (num == 0)
    {
        return "0";
    }

    unsigned int n = num;
    string res;
    char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    while (n != 0)
    {
        res = mp[(n & 15)] + res;
        n >>= 4;
    }

    return res;
}

int main()
{
    int n = 26;
    cout << toHex(n);

    return 0;
}