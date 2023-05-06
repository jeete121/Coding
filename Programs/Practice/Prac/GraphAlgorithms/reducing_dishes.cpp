#include <bits/stdc++.h>
using namespace std;

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    int sum = 0;
    int ans = 0;
    int n = satisfaction.size();
    for (int i = n - 1; i >= 0; i--)
    {
        sum += satisfaction[i];
        if (sum > 0)
            ans += sum;
        else
            break;
    }

    return ans;
}

int main()
{
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(satisfaction);
    return 0;
}