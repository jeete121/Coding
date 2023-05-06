#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayProductExceptSelf(vector<int> arr)
{
    int n = arr.size();

    //make left and right array
    int left[n + 1];
    int right[n + 1];

    left[0] = 1;

    //find the product of elements
    //left of index i
    for (int i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }

    right[n - 1] = 1;

    //find the product of elements
    //right of index i
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * arr[i + 1];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(left[i] * right[i]);
    return ans;
}
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> res = findArrayProductExceptSelf(arr);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

//Time Complexity :O(n)
//Space Complexity: O(n)