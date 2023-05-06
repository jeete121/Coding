#include <bits/stdc++.h>
using namespace std;

int countLargestGroup(int n)
{
    int sum[n];
    if (n == 1)
        return 1;
    for (int i = 0; i < n; i++)
        sum[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i, l = i - 1;
        while (j)
        {
            sum[l] += j % 10;
            j = j / 10;
        }
    }
    vector<int> vec;
    sort(sum, sum + n);
    for (int i = 0; i < n - 1; i++)
    {
        int cnt = 1;
        while (i < n - 1 && sum[i] == sum[i + 1])
        {
            cnt++;
            i++;
        }
        vec.push_back(cnt);
    }
    if (sum[n - 1] != sum[n - 2])
        vec.push_back(1);
    sort(vec.begin(), vec.end());
    int cnt = 0;
    for (int i = vec.size() - 1; i >= 0; i--)
        if (vec[i] == vec[vec.size() - 1])
            cnt++;
        else
            break;
    return cnt;
}

int main()
{
    int n = 13;
    cout << countLargestGroup(n);
    return 0;
}