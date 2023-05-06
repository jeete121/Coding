#include <bits/stdc++.h>
using namespace std;

int charSum(string s)
{
    int sum = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        sum += s[i] - 'a' + 1;
    }
    return sum;
}
int main()
{
    string s = "aba";

    cout << charSum(s) << "\n";

    return 0;
}