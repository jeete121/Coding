#include <bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text)
{
    int n = text.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[text[i]]++;
    int arr[5];
    arr[0] = mp['b'];
    arr[1] = mp['a'];
    arr[2] = mp['l'] / 2;
    arr[3] = mp['o'] / 2;
    arr[4] = mp['n'];
    sort(arr, arr + 5);
    return arr[0];
}

int main()
{
    string text = "nlaebolko";
    cout << maxNumberOfBalloons(text);
    return 0;
}