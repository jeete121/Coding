#include <bits/stdc++.h>
using namespace std;

void rankArray(vector<int> &arr)
{
    vector<int> newArray;
    for (int i = 0; i < arr.size(); i++)
        newArray.push_back(arr[i]);

    sort(newArray.begin(), newArray.end());

    map<int, int> rank;
    int rankCount = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (rank[newArray[i]] == 0)
        {
            rank[newArray[i]] = rankCount++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rank[arr[i]];
    }
}
int main()
{
    vector<int> arr = {4, 10, 5, 3, 6};

    rankArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}