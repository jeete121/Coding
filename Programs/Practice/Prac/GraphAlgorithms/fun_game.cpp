#include <bits/stdc++.h>
using namespace std;

vector<int> funGame(int n, vector<int> &arr)
{
    stack<int> st;
    queue<int> q;

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        st.push(arr[i]);
        q.push(arr[i]);
    }
    while (!st.empty() && !q.empty())
    {
        int b = st.top();
        int a = q.front();
        if (a > b)
        {
            res.push_back(1);
            st.pop();
        }
        else if (a < b)
        {
            res.push_back(2);
            q.pop();
        }
        else
        {
            res.push_back(0);
            st.pop();
            q.pop();
        }
    }
    return res;
}
int main()
{

    int n = 3;

    vector<int> arr = {1, 2, 3};

    vector<int> res = funGame(n, arr);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}