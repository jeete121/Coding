#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    if (height.size() <= 2)
        return 0;
    vector<int> left(height.size());
    vector<int> right(height.size());

    left[0] = height[0];
    right[right.size() - 1] = height[height.size() - 1];

    //find left height for all the indices
    for (int i = 1; i < right.size(); i++)
    {
        left[i] = max(height[i], left[i - 1]);
    }

    //find the right height of all the indices
    for (int i = right.size() - 2; i >= 0; i--)
    {
        right[i] = max(height[i], right[i + 1]);
    }
    int water = 0;

    //find the total water collected
    for (int i = 0; i < right.size(); i++)
    {
        water += max(min(right[i], left[i]) - height[i], 0);
    }
    return water;
}

int main()
{
    vector<int> height = {3, 0, 1, 3, 0, 5};

    cout << trap(height);

    return 0;
}