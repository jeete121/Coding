#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    long long int i = 0;
    long long int n = nums.size();
    long long int j = 0;
    vector<string> res;
    while (i < n)
    {
        j = i;
        string str = "";
        str += to_string(nums[j]);
        i++;
        while (i < n && (long)nums[i] - (long)nums[i - 1] == 1)
            i++;
        if (i > j + 1)
            str = (str + "->" + to_string(nums[i - 1]));
        res.push_back(str);
    }
    return res;
}

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = summaryRanges(nums);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1] << "]";
    return 0;
}