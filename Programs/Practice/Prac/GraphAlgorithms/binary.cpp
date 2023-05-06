#include <bits/stdc++.h>
using namespace std;

int binary(int n, string s)
{

    int i = 0, j = n - 1;
    while (s[i] == '0')
        i++;
    while (s[j] == '0')
        j--;
    int cnt = 0;
    while (true)
    {
        while (i < j)
        {
            if (s[j] == '1')
                cnt++;
            j--;
        }
        i = i + 1;
        j = s.size() - 1;
        while (s[i] == '0')
            i++;
        if (i == j)
            break;
    }
    return cnt;
}
int main()
{
    int n = 5;

    string s = "01101";

    cout << binary(n, s) << "\n";

    return 0;
}