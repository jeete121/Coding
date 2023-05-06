#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayProductExceptSelf(vector<int> arr)
{
    vector<int> res;

    //find the size of array
    int n = arr.size();

    //iterate for each index
    for (int i = 0; i < n; i++)
    {

        //initialize the product variable
        int product = 1;
        for (int j = 0; j < n; j++)
        {

            //if index is same then
            //continue
            if (i == j)
            {
                continue;
            }

            //update the product
            else
            {
                product = product * arr[j];
            }
        }

        //add into the result array
        res.push_back(product);
    }

    //return the result array
    return res;
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

//Time Complexity: O(n^2)
//Space Complexity: O(1)