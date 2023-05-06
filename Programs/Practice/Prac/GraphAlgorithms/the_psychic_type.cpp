#include <bits/stdc++.h>
using namespace std;

bool thePsychicType(int n, int arr[], int s, int e)
{
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = arr[i - 1];

    set<int> st;
    st.insert(s);
    int flag = 0;
    while (s != e)
    {
        s = a[s];
        if (st.find(s) != st.end())
        {
            flag = 1;
            break;
        }
        st.insert(s);
    }
    if (flag == 0)
        return true;
    else
        return false;
}
int main()
{

    int n = 5;

    int arr[] = {3, 4, 2, 5, 5};
    int s = 1, e = 4;

    if (thePsychicType(n, arr, s, e))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}