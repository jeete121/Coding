#include <bits/stdc++.h>
using namespace std;

int numFactoredBinaryTrees(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, unsigned long long> umap;
    int total = 0;
    int MOD = 1000000007;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        umap[curr] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0)
            {
                int a = arr[j];
                int b = arr[i] / arr[j];
                if (a > b)
                {
                    break;
                }
                else if (a == b)
                {
                    umap[curr] += umap[a] * umap[b];
                }
                else if (umap.find(b) != umap.end())
                {
                    umap[curr] += 2 * umap[a] * umap[b];
                }
            }
        }
        total = (total + umap[curr]) % MOD;
    }
    return total;
}

int main()
{
    vector<int> arr = {2, 4, 5, 10};

    cout << numFactoredBinaryTrees(arr);

    return 0;
}