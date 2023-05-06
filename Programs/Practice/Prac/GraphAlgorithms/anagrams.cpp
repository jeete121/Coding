#include <bits/stdc++.h>
using namespace std;

int anagrams(string a, string b)
{
    int f[26] = {0}, f1[26] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        f[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        f1[b[i] - 'a']++;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
        sum += abs(f[i] - f1[i]);
    return sum;
}
int main()
{

    string a = "cde", b = "abc";

    cout << anagrams(a, b) << "\n";

    return 0;
}