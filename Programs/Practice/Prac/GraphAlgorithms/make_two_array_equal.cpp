#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    int n = target.size(), m = arr.size();

    //if length of both array is different
    //then return false
    if (n != m)
        return false;

    //sort both the arrays
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        //if current value of both array is not same then
        //return false
        if (target[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> target = {1, 2, 3, 4}, arr = {2, 4, 1, 3};
    if (canBeEqual(target, arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}