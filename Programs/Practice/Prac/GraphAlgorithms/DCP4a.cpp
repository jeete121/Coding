#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    set<int> st;

    //insert positive number into the set
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            st.insert(nums[i]);
        }
    }
    int ans;
    for (int i = 1;; i++)
    {
        //if missing number found then break
        if (st.find(i) == st.end())
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 4, -1, 1};

    cout << firstMissingPositive(arr);

    return 0;
}

//Time Compplexity :O(maximum element in the array)
//Space Complexity: O(n)