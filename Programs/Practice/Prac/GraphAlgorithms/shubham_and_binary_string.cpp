#include <bits/stdc++.h>
using namespace std;

int countZerosInBinaryString(int n, string s)
{

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt++;
    }
    return cnt;
}
int main()
{

    int n = 5;

    string s = "10011";

    cout << countZerosInBinaryString(n, s) << "\n";

    return 0;
}