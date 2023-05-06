#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num)
{
    string str = to_string(num);
    for (int i = 0; i < str.size(); i++)
    {
        char m = str[i];
        int flag = 0;
        int pos;
        for (int j = str.size() - 1; j > i; j--)
        {
            if (str[j] > m)
            {
                m = str[j];
                pos = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            char temp = str[pos];
            str[pos] = str[i];
            str[i] = temp;
            break;
        }
    }
    int ans = stoi(str);
    return ans;
}

int main()

{
    int n = 2736;
    cout << maximumSwap(n);
    return 0;
}