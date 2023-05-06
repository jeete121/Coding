#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size(), m = B.size();
    int i = 0, j = 0;
    vector<vector<int>> res;
    while (i < n && j < m)
    {
        int low = max(A[i][0], B[j][0]);
        int high = min(A[i][1], B[j][1]);
        if (low <= high)
            res.push_back({low, high});
        if (A[i][1] < B[j][1])
            i++;
        else
            j++;
    }
    return res;
}

int main()
{
    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    vector<vector<int>> inter = intervalIntersection(firstList, secondList);
    cout << "[";
    for (int i = 0; i < inter.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < inter[i].size(); j++)
        {
            cout << inter[i][j];
            if (j != inter[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != inter.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}