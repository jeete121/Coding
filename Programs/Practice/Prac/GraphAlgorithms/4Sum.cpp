#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    vector<vector<int>> result;

    //if size is less than 4
    if (nums.size() < 4)
        return {};

    //sort the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++)
    {
        //if same then continue
        if (i > 0 and nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            //if same then continue
            if (j > i + 1 and nums[j] == nums[j - 1])
                continue;

            //now set other two pointers
            int left = j + 1, right = nums.size() - 1;
            while (left < right)
            {

                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                //is sum is same as target
                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right and nums[left] == nums[left - 1])
                        left++;

                    while (left < right and nums[right] == nums[right + 1])
                        right--;
                }

                //if sum is less than target
                else if (sum < target)
                    left++;

                //if sum is greater than target
                else
                    right--;
            }
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = fourSum(nums, target);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}