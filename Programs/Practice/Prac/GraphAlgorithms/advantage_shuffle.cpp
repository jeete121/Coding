#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};
vector<int> advantageCount(vector<int> &A, vector<int> &B)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (int i = 0; i < B.size(); i++)
    {
        pq.push({B[i], i});
    }
    sort(A.begin(), A.end());
    vector<int> left;
    vector<int> ans(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > pq.top().first)
        {
            ans[pq.top().second] = A[i];
            pq.pop();
        }
        else
        {
            left.push_back(A[i]);
        }
    }
    int i = 0;
    while (!pq.empty())
    {
        ans[pq.top().second] = left[i++];
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> A = {2, 7, 11, 15};
    vector<int> B = {1, 10, 4, 11};

    vector<int> res = advantageCount(A, B);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}