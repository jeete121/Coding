#include <bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & 1)
        {
            cnt++;
            if (cnt == 3)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    if (flag == 1)
        return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    if (threeConsecutiveOdds(arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}