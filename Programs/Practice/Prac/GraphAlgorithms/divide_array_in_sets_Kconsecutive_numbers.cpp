#include <bits/stdc++.h>
using namespace std;

bool isPossibleDivide(vector<int> &nums, int k)
{
    //sort the array
    sort(nums.begin(), nums.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //iterate for all the elements of the
    //array
    for (int num : nums)
    {
        while (!pq.empty() && (pq.top().first < num - 1 || pq.top().second == k))
        {
            if (pq.top().second != k)
            {
                return false;
            }

            pq.pop();
        }

        if (pq.empty() || pq.top().first == num)
        {
            pq.push(make_pair(num, 1));
            continue;
        }

        int size = pq.top().second + 1;
        pq.pop();
        pq.push(make_pair(num, size));
    }

    while (!pq.empty())
    {
        if (pq.top().second != k)
        {
            return false;
        }

        pq.pop();
    }

    return true;
}
int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 6};
    int k = 4;

    if (isPossibleDivide(nums, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}