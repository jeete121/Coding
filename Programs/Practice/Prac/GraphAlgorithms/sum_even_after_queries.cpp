#include <bits/stdc++.h>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int> &A,
                                vector<vector<int>> &queries)
{

    vector<int> res;
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
            sum += A[i];
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int val = queries[i][0];
        int index = queries[i][1];
        if (A[index] % 2 == 0)
        {
            sum -= A[index];
        }
        A[index] = A[index] + val;
        if (A[index] % 2 == 0)
        {
            sum += A[index];
        }
        res.push_back(sum);
    }
    return res;
}

int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};

    vector<int> res = sumEvenAfterQueries(A, queries);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}