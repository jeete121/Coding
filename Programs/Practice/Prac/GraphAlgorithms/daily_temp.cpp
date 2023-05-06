#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> st;
    st.push(0);
    int index;
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && T[i] > T[st.top()])
        {
            index = st.top();
            res[index] = i - index;
            st.pop();
        }
        if (st.empty() || T[i] <= T[st.top()])
            st.push(i);
    }
    return res;
}

int main()
{

    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(T);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << " ,";
    cout << res[res.size() - 1] << "]";
    return 0;
}