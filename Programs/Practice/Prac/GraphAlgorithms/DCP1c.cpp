#include <bits/stdc++.h>
using namespace std;

bool isPairSum(vector<int> arr, int k)
{
    //find the size of array
    int n = arr.size();

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int diff = k - arr[i];
        
        //if pair with sum k is found then
        //return true
        if (st.find(diff) != st.end())
        {
            return true;
        }

        //insert the current element into
        //the set
        st.insert(arr[i]);
    }
    //if no pair then return false
    return false;
}
int main()
{
    vector<int> arr = {10, 15, 3, 7};

    int k = 17;

    if (isPairSum(arr, k))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(n)