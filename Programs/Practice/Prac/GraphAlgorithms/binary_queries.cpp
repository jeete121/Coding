#include <bits/stdc++.h>
using namespace std;

void binaryQueries(int n, int q, int a[],
                   vector<vector<int>> &queries)
{
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    for (int i = 0; i < q; i++)
    {
        int c = queries[i][0];

        if (c == 0)
        {
            int x = queries[i][1];
            int y = queries[i][2];
            if (arr[y] == 1)
                cout << "ODD\n";
            else
                cout << "EVEN\n";
        }
        else
        {
            int x = queries[i][1];
            arr[x] = !arr[x];
        }
    }
}
int main()
{

    int n = 5, q = 2;

    int a[n] = {1, 0, 1, 1, 0};

    vector<vector<int>> queries = {{1, 2},
                                   {0, 1, 4}};

    binaryQueries(n, q, a, queries);

    return 0;
}