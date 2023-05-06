#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int maxVowels(string s, int k)
{
    int n = s.size();
    int arr[n];
    if (isvowel(s[0]))
        arr[0] = 1;
    else
        arr[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (isvowel(s[i]))
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1];
    }
    int max1 = 0;
    max1 = arr[k - 1];
    for (int i = k; i < n; i++)
    {
        int x = arr[i] - arr[i - k];
        if (x > max1)
            max1 = x;
    }
    return max1;
}

int main()
{
    string s = "abciiidef";
    int k = 3;
    cout << maxVowels(s, k);
    return 0;
}