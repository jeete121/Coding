#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int m, int num)
{
    int res;
    for (int i = 0; i < m; i++)
        if (arr[i] == num)
        {
            res = i;
            break;
        }
    return res;
}
vector<int> processQueries(vector<int> &queries, int m)
{
    int arr[m];
    for (int i = 0; i < m; i++)
        arr[i] = i + 1;
    vector<int> res;
    for (int i = 0; i < queries.size(); i++)
    {
        int pos = find(arr, m, queries[i]);
        res.push_back(pos);
        int temp = arr[pos];
        for (int j = pos; j > 0; j--)
            arr[j] = arr[j - 1];
        arr[0] = temp;
    }
    return res;
}

int main()
{
    vector<int> queries = {3, 1, 2, 1};
    int m = 5;
    vector<int> res = processQueries(queries, m);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << ",";
    cout << res[res.size() - 1] << "]";
    return 0;
}