#include <bits/stdc++.h>
using namespace std;

string chocolateRooms(vector<int> &arr, vector<vector<string>> &s,
                      int n, int k)

{
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        int p = arr[i];

        for (int j = 0; j < p; j++)
        {

            st.insert(s[i][j]);
        }
    }
    if (st.size() >= k)
        return "Yes";
    else
        return "No";
}
int main()
{
    int n = 3, k = 2;

    vector<int> arr = {1, 2, 1};

    vector<vector<string>> s = {{"KITKAT"},
                                {"FIVESTAR", "KITKAT"},
                                {"KITKAT"}};

    cout << chocolateRooms(arr, s, n, k) << "\n";

    return 0;
}