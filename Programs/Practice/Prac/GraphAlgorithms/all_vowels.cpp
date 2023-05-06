#include <bits/stdc++.h>
using namespace std;

bool allVowels(int n, string s)
{

    int a[5] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a[0]++;
        else if (s[i] == 'e')
            a[1]++;
        else if (s[i] == 'i')
            a[2]++;
        else if (s[i] == 'o')
            a[3]++;
        else if (s[i] == 'u')
            a[4]++;
    }
    sort(a, a + 5);
    if (a[0] > 0)
        return true;
    else
        return false;
}
int main()
{
    int n = 8;

    string s = "atuongih";

    if (allVowels(n, s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}