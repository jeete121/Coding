#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> maxstack, st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            if (maxstack.empty())
                maxstack.push(y);
            else
            {
                if (maxstack.top() < y)
                    maxstack.push(y);
                else
                    maxstack.push(maxstack.top());
            }
            st.push(y);
        }
        if (x == 2)
        {
            if (!maxstack.empty())
                maxstack.pop();
            st.pop();
        }
        if (x == 3)
            cout << maxstack.top() << "\n";
    }
    return 0;
}
