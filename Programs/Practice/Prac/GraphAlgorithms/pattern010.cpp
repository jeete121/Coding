#include <bits/stdc++.h>
using namespace std;

int countPattern(string str)
{
    int count = 0;

    int j = 0;

    int i = 1, n = str.size();

    while (i < n)
    {
        if (str[i] == '1' && str[j] == '0')
        {
            while (str[i] == '1')
                i++;
            if (str[i] == '0')
            {
                count++;
            }
        }
        j = i;
        i++;
    }
    return count;
}
int main()
{
    string str = "011011010";

    cout << countPattern(str);

    return 0;
}