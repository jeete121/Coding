#include <bits/stdc++.h>
using namespace std;

void nearestSmallestElements(int n, int a[])
{
    stack<int> st;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        if (st.empty())
            arr[i] = -1;
        else
            arr[i] = st.top();
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n = 8;
    int a[n] = {39, 27, 11, 4, 24, 32, 32, 1};

    nearestSmallestElements(n, a);

    return 0;
}
