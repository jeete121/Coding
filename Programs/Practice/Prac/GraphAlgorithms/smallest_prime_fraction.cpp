#include <bits/stdc++.h>
using namespace std;

class compare
{
public:
    bool operator()(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, compare> pq;
    int n = A.size();
    for (int i = 1; i < A.size(); ++i)
    {
        pq.push({(A[0] * 1.0 / A[i] * 1.0), {0, i}});
    }
    pair<double, pair<int, int>> p;
    while (K > 0)
    {
        p = pq.top();
        pq.pop();
        if (p.second.first + 1 < p.second.second)
        {
            pq.push({(A[p.second.first + 1] * 1.0 / A[p.second.second] * 1.0), {p.second.first + 1, p.second.second}});
        }
        K--;
    }
    vector<int> res = {A[p.second.first], A[p.second.second]};
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;

    vector<int> res = kthSmallestPrimeFraction(arr, k);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}