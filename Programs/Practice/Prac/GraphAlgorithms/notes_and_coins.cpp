#include <bits/stdc++.h>
using namespace std;

void notesCoins(int n, vector<pair<string, int>> &coins)
{
    string s;
    vector<int> vc, vn;
    for (int i = 0; i < n; i++)
    {
        if (coins[i].first == "Coin")
            vc.push_back(coins[i].second);
        else
            vn.push_back(coins[i].second);
    }
    if (vc.size() > 0)
    {
        cout << "Coins :\n";
        for (int i = 0; i < vc.size(); i++)
            cout << vc[i] << "\n";
    }
    if (vn.size() > 0)
    {
        cout << "Notes :\n";
        for (int i = 0; i < vn.size(); i++)
            cout << vn[i] << "\n";
    }
}
int main()
{
    int n = 7;
    vector<pair<string, int>> coins = {{"Note", 83},
                                       {"Coin", 19},
                                       {"Coin", 85},
                                       {"Note", 8},
                                       {"Note", 30},
                                       {"Coin", 56},
                                       {"Coin", 53}};

    notesCoins(n, coins);

    return 0;
}