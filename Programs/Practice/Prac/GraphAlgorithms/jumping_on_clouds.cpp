#include <bits/stdc++.h>
using namespace std;

int jumpingOnClouds(vector<int> arr, int n)
{
    int cnt = 0;
    int i = 0, j, k;
    while (i < n)
    {
        j = i + 1;
        k = i + 2;
        if (arr[k] == 0)
        {
            i = i + 2;
            cnt++;
        }
        else
        {
            i = i + 1;
            cnt++;
        }
    }
    return cnt - 1;
}

int main()
{
    int n = 7;
    vector<int> arr = {0, 0, 1, 0, 0, 1, 0};
    cout << jumpingOnClouds(arr, n);
    return 0;
}
