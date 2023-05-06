#include <bits/stdc++.h>
using namespace std;

int max_elem(stack<pair<int, int>> &st1, stack<pair<int, int>> &st2)
{
    if (st1.empty() || st2.empty())
    {
        if (st1.empty())
            return st2.top().second;
        return st1.top().second;
    }
    return max(st1.top().second, st2.top().second);
}
void add(int new_elem, stack<pair<int, int>> &st1, stack<pair<int, int>> &st2)
{
    int max1;
    if (st1.empty())
        max1 = new_elem;
    else
        max1 = max(new_elem, st1.top().second);
    st1.push({new_elem, max1});
}
void remove(stack<pair<int, int>> &st1, stack<pair<int, int>> &st2)
{
    if (st2.empty())
    {
        while (!st1.empty())
        {
            int element = st1.top().first;
            st1.pop();
            int max1;
            if (st2.empty())
                max1 = element;
            else
                max1 = max(element, st2.top().second);
            st2.push({element, max1});
        }
    }
    st2.pop();
}
vector<int> solve(vector<int> arr, vector<int> queries)
{
    vector<int> res;
    int n = arr.size();
    for (int j = 0; j < queries.size(); j++)
    {
        int d = queries[j];

        stack<pair<int, int>> st1, st2;
        for (int i = 0; i < d; i++)
            add(arr[i], st1, st2);
        int ans = max_elem(st1, st2);
        for (int i = d; i < n; i++)
        {
            remove(st1, st2);
            add(arr[i], st1, st2);
            ans = min(max_elem(st1, st2), ans);
        }
        res.push_back(ans);
    }
    return res;
}
int main()
{
    int n = 5, m = 5;
    vector<int> arr = {33, 11, 44, 11, 55};
    vector<int> queries = {1, 2, 3, 4, 5};
    vector<int> res = solve(arr, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
