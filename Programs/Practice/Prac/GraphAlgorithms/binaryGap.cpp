#include <bits/stdc++.h>
using namespace std;

//convert number to binary string
string binary(int n)
{
    string res = "";
    while (n > 0)
    {
        int temp = n % 2;

        res = to_string(temp) + res;
        n = n / 2;
    }
    return res;
}
int binaryGap(int n)
{
    string bString = binary(n);

    int ans = 0;
    int len = bString.size();
    int i = 0;
    while (i < len)
    {
        int count = 0;
        while (i < len && bString[i] == '0')
        {
            i++;
        }
        int j = i;
        i++;
        while (i < len && bString[i] == '0')
        {
            i++;
        }
        if (i == len)
        {
            break;
        }
        else
        {
            ans = max(ans, i - j);
        }
    }
    return ans;
}

int main()
{
    int n = 22;

    cout << binaryGap(n);

    return 0;
}