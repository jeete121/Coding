#include <bits/stdc++.h>
using namespace std;

int hurdleRace(int k, vector<int> height)
{
    int n = height.size();
    int large = height[0];
    for (int i = 1; i < n; i++)
        if (height[i] > large)
            large = height[i];
    if (k > large)
        return 0;
    else
        return large - k;
}

int main()
{
    int n = 5, k = 4;

    vector<int> height = {1, 6, 3, 5, 2};
    cout << hurdleRace(k, height);
    return 0;
}
