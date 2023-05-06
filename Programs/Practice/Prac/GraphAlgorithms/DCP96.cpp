#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

//function to find all the permutaions of the
//given string
void permutations(vector<int> arr, int l, int r)
{

    //base case if l and r same
    //then push the string into the
    //vector of strings
    if (l == r)
    {
        ans.push_back(arr);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {

            //swap the values
            swap(arr[l], arr[i]);

            //call for permutation
            permutations(arr, l + 1, r);

            //backtrack
            swap(arr[l], arr[i]);
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    ans.clear();
    permutations(arr, 0, arr.size() - 1);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}