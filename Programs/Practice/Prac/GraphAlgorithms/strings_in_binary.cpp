#include <bits/stdc++.h>
using namespace std;

int stringInBinary(int n, string s)
{

    int i = 0, j = n - 1;
    int cnt = 0, k;
    while (i < j)
    {
        while (i < j && s[i] == '0')
            i++;
        while (i < j && s[j] == '0')
            j--;

        while (i < j)
        {
            if (s[j] == '1')
            {
                cnt++;
            }
            j--;
        }
        j = n - 1;
        i = i + 1;
    }
    return cnt;
}
int main()
{

    int n = 4;
    string s = "1111";

    cout << stringInBinary(n, s) << "\n";

    return 0;
}