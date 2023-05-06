#include <bits/stdc++.h>
using namespace std;

void binaryMatrix(int n, int m, vector<string> &v)
{
    set<string> st;
    for (int i = 0; i < n; i++)
    {

        st.insert(v[i]);
    }
    if (st.size() == n)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{

    int n = 3, m = 3;
    vector<string> v = {"101",
                        "000",
                        "100"};
    binaryMatrix(n, m, v);

    return 0;
}