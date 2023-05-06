#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &mainArray, vector<int> &subArray)
{

    int i = 0, j = 0;
    int m = mainArray.size();
    int n = subArray.size();

    //sort both the arrays
    sort(mainArray.begin(), mainArray.end());
    sort(subArray.begin(), subArray.end());

    //apply two poniter approach
    while (i < n && j < m)
    {
        if (mainArray[j] == subArray[i])
        {
            i++;
            j++;
        }
        else if (mainArray[j] < subArray[i])
            j++;

        else if (mainArray[j] > subArray[i])
            return false;
    }

    if (i < n)
        return false;
    else
        return true;
}

int main()
{
    vector<int> mainArray = {1, 2, 3, 2, 5, 6, 2};
    vector<int> subArray = {2, 2, 2};

    if (isSubset(mainArray, subArray))
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}