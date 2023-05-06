#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{

    int altitudeSum = 0;
    int maxAltitude = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        altitudeSum += gain[i];
        maxAltitude = max(maxAltitude, altitudeSum);
    }
    return maxAltitude;
}

int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << largestAltitude(gain);

    return 0;
}