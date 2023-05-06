#include <bits/stdc++.h>
using namespace std;

int getKay(vector<int> a, int n)
{
    int b[32];
    for (int i = 0; i < 32; i++)
        b[i] = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        st.insert(temp);
        for (int j = 0; j < 32; j++)
        {
            b[j] += ((temp >> j) & 1);
        }
    }

    for (int i = 0; i < 32; i++)
    {
        b[i] %= 2;
    }

    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (b[i] != 0)
            ans += pow(2, i);
    }

    if (ans == 0)
        return -1;
    for (int i = 0; i < n; i++)
    {
        //if not in set then return -1
        if (st.find(a[i] ^ ans) == st.end())
            return -1;
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<int> a = {5, 6, 9, 10, 13, 14};
    cout << getKay(a, n) << "\n";
}
