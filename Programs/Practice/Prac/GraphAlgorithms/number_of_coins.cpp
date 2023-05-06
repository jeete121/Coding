#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &piles)
{

    //sort the array in decreasing order
    sort(piles.begin(), piles.end(), greater<int>());
    int ans = 0;
    int cnt = 0;

    //iterate till the length of the array
    for (int i = 1; i < piles.size(); i += 2)
    {
        if (piles.size() - i >= cnt)
        {
            ans += piles[i];
            cnt++;
        }
        else
            break;
    }
    return ans;
}

int main()
{
    vector<int> piles = {2, 4, 1, 2, 7, 8};
    cout << maxCoins(piles);
    return 0;
}