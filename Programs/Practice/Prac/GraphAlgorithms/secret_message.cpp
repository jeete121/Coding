#include <bits/stdc++.h>
using namespace std;

string secretMessage(int n, int K, string s)
{
    int i = 0;
    while (i < s.size())
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (s[i] - 'A' + K) % 26;
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (s[i] - 'a' + K) % 26;
        else if (s[i] >= '0' && s[i] <= '9')
            s[i] = '0' + (s[i] - '0' + K) % 10;
        i++;
    }
    return s;
}
int main()
{

    int n = 12, K = 4;

    string s = "Hello-World!";

    cout << secretMessage(n, K, s) << "\n";

    return 0;
}