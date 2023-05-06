#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &v)
{
    vector<vector<int>> res;

    //sort the 2d array according to
    //firt value
    sort(v.begin(), v.end());

    //if no elements
    if (v.size() == 0)
        return res;

    //stack
    stack<pair<int, int>> st;

    //insert first pair into the stack
    st.push({v[0][0], v[0][1]});
    for (int i = 1; i < v.size(); i++)
    {

        //top of stack
        pair<int, int> p = st.top();

        //if start is less than stack top
        //second then add into the stack
        if (p.second < v[i][0])
            st.push({v[i][0], v[i][1]});
        else
        {
            //update end interval
            if (p.second < v[i][1])
                p.second = v[i][1];

            //pop from stack
            st.pop();
            //push into the stack
            st.push(p);
        }
    }
    while (!st.empty())
    {
        pair<int, int> p = st.top();
        st.pop();
        vector<int> x;
        x.push_back(p.first);
        x.push_back(p.second);
        res.push_back(x);
    }

    //reverse the result
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {5, 8}, 
                                     {4, 10}, {20, 25}};
    intervals = merge(intervals);

    cout << "[";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[";
        cout << intervals[i][0] << "," << intervals[i][1];
        cout << "]";
        if (i != intervals.size() - 1)
            cout << ",";
    }
    cout << "]";
}
