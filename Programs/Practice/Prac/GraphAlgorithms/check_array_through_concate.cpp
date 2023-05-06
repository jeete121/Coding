#include <bits/stdc++.h>
using namespace std;

bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
{
    for (int i = 0; i < arr.size();)
    {
        int k = -1;
        for (int j = 0; j < pieces.size(); j++)
        {
            if (pieces[j][0] == arr[i])
            {
                k = j;
                break;
            }
        }
        if (k == -1)
            return false;
        else
        {
            int flag = 0;
            for (int l = 0; l < pieces[k].size(); l++)
            {
                if (pieces[k][l] == arr[i])
                    i++;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {15, 88};
    vector<vector<int>> pieces = {{88}, {15}};
    if (canFormArray(arr, pieces))
        cout << "true";
    else
        cout << "false";
    return 0;
}