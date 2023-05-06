#include <bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries)
{
    long long *arr = new long long[n + 2];
    fill(arr, arr + n + 2, 0);
    int a, b, k;
    int m = queries.size();
    for (long long i = 0; i < m; i++)
    {
        a = queries[i][0];
        b = queries[i][1];
        k = queries[i][2];
        arr[a] += k;
        arr[b + 1] += -k;
    }
    for (long long i = 2; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
    long long max1 = arr[1];
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] > max1)
        {
            max1 = arr[i];
        }
    }
    return max1;
}
int main()
{
    long long n = 5, m = 3;

    vector<vector<int>> queries = {{1, 2, 100}, {2, 5, 100}, {3, 4, 100}};
    cout << arrayManipulation(n, queries);
    return 0;
}
