#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 6;

    int ranked[n] = {100, 90, 90, 80, 75, 60};

    int m = 5;
    int player[m] = {50, 65, 77, 90, 102};

    vector<pair<int, int>> v;
    int i = 1;
    int rank = 1;
    while (i < n)
    {
        while (i < n && ranked[i] == ranked[i - 1])
        {
            v.push_back({ranked[i - 1], rank});
            i++;
        }
        v.push_back({ranked[i - 1], rank});
        rank++;
        i++;
    }
    v.push_back({ranked[i - 1], rank});
    int j = n - 1;
    for (int i = 0; i < m; i++)
    {

        if (player[i] == v[j].first)
        {
            cout << v[j].second << "\n";
        }
        else if (player[i] < v[j].first)
        {
            cout << v[j].second + 1 << "\n";
        }
        else
        {
            while (j >= 0 && v[j].first < player[i])
                j--;
            if (j >= 0)
            {
                if (player[i] == v[j].first)
                    cout << v[j].second << "\n";
                else
                    cout << v[j].second + 1 << "\n";
            }
            else
                cout << 1 << "\n";
        }
    }
    return 0;
}
