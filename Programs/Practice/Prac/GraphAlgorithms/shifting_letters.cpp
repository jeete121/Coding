#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string S, vector<int> &shifts)
{
    string str = "";
    int n = S.size();
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += shifts[i];
        long long x = (sum + S[i] - 'a');
        x = x % 26;
        sum = sum % 26;
        str += 'a' + x;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string S = "abc";
    vector<int> shifts = {3, 5, 9};
    cout << shiftingLetters(S, shifts);
    return 0;
}