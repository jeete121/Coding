#include <bits/stdc++.h>
using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int n = releaseTimes.size();
    int max1 = releaseTimes[0];
    char ans = keysPressed[0];
    for (int i = 1; i < n; i++)
    {
        if (releaseTimes[i] - releaseTimes[i - 1] > max1)
        {
            max1 = releaseTimes[i] - releaseTimes[i - 1];
            ans = keysPressed[i];
        }
        else if (releaseTimes[i] - releaseTimes[i - 1] == max1)
        {
            if (keysPressed[i] > ans)
                ans = keysPressed[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> releaseTimes = {12, 23, 36, 46, 62};
    string keysPressed = "spuda";
    cout << slowestKey(releaseTimes, keysPressed);
    return 0;
}