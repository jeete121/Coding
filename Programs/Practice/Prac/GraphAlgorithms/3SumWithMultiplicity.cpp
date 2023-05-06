#include <bits/stdc++.h>
using namespace std;

int threeSumMulti(vector<int> &arr, int target)
{
    int n = arr.size();

    //sort the array
    sort(arr.begin(), arr.end());
    const long long mod = 1e9 + 7;
    long long ans = 0;

    //iterate till the length of array -2
    for (int i = 0; i < n - 2; i++)
    {

        //set other two pointers
        int l = i + 1, r = n - 1;

        //iterate till first pointer is
        //less than last pointer
        while (l < r)
        {

            //sum including these points
            int now = arr[i] + arr[l] + arr[r];

            //if target is greatet then
            //increment the first pointer
            if (now < target)
            {
                l++;
                continue;
            }

            //else decrement the second pinter
            if (now > target)
            {
                r--;
                continue;
            }

            //set left count and right count as 1
            int lcnt = 1, rcnt = 1;

            //update left count
            while (l < r && arr[l] == arr[l + 1])
            {
                lcnt++;
                l++;
            }

            //update right count
            while (l < r && arr[r] == arr[r - 1])
            {
                rcnt++;
                r--;
            }

            //update answer
            if (l == r)
                ans += lcnt * (lcnt - 1) / 2;
            else
                ans += lcnt * rcnt;

           //take mod
            ans %= mod;
            l++;
            r--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;

    cout << threeSumMulti(arr, target);

    return 0;
}