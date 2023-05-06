#include <bits/stdc++.h>
using namespace std;

//funtion to find the longest consecutive
//sequence
int longestConsecutive(vector<int> &nums)
{

    //sort the array
    sort(nums.begin(), nums.end());

    // if the array is empty then return 0
    if (nums.size() == 0)
        return 0;
    int cnt = 1, res = 1;

    for (int i = 1; i < nums.size(); i++)
    {

        //if current element is 1 more then the previous
        //one then increment the count
        if (nums[i] == 1 + nums[i - 1])
        {
            cnt++;
        }

        //if current element is same as the
        //previous element then continue to the
        //next position
        else if (nums[i] == nums[i - 1])
            continue;

        //else update
        else
        {
            //update the result
            res = max(res, cnt);
            cnt = 1;
        }
    }

    //update the result
    res = max(res, cnt);
    return res;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(arr);

    return 0;
}