#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    int rev = 0;
    int m = n;
    while (m > 0)
    {
        rev = rev * 10 + m % 10;
        m = m / 10;
    }
    if (rev == n)
        return true;
    return false;
}
int longestPalindrome(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (isPalindrome(arr[i]))
        {
            return arr[i];
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 4, 584, 88, 252};

    cout << longestPalindrome(arr);

    return 0;
}