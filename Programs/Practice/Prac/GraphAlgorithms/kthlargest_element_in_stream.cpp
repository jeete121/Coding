#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int len;
    KthLargest(int k, vector<int> &nums)
    {
        len = k;
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
            if (q.size() > k)
                q.pop();
        }
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > len)
            q.pop();
        return q.top();
    }
};

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kthLargest(k, nums);

    cout << "[";
    cout << kthLargest.add(3) << ", ";
    cout << kthLargest.add(5) << ", ";
    cout << kthLargest.add(10) << ", ";
    cout << kthLargest.add(9) << ", ";
    cout << kthLargest.add(4);
    cout << "]";

    return 0;
}