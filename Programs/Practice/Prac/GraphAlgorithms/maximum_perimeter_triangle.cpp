#include <bits/stdc++.h>
using namespace std;

vector<int> maximumPerimeterTriangle(vector<int> arr)
{

    int n = arr.size();
    vector<int> res;
    //sort the array

    sort(arr.begin(), arr.end());
    int ans = -1;
    int x = 0, y = 0, z = 0;
    int flag = 0;
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] + arr[i - 1] > arr[i + 1])
        {
            x = arr[i - 1];
            y = arr[i];
            z = arr[i + 1];
            flag = 1;
            break;
        }
        else

            continue;
    }
    if (flag == 0)
        res.push_back(ans);
    else
    {
        res.push_back(x);
        res.push_back(y);
        res.push_back(z);
    }
    return res;
}

int main()
{
    int n = 5;

    vector<int> arr = {1, 1, 1, 3, 3};

    vector<int> ans = maximumPerimeterTriangle(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
//Time Complexity: O(nlog(n))
