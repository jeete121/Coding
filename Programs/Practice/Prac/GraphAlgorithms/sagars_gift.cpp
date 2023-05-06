#include <bits/stdc++.h>
using namespace std;

string gift(int n, int a[])
{

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int j = a[i];
        if (j == 0)
            v.push_back(0);
        while (j)
        {
            v.push_back(j % 10);
            j = j / 10;
        }
    }
    string str = "";
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
        str += to_string(v[i]);

    return str;
}
int main()
{
    int n = 5;

    int a[n] = {1, 2, 20, 31, 5};

    cout << gift(n, a) << "\n";

    return 0;
}