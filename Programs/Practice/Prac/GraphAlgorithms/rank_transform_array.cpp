#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int> &arr)
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
    return arr;
}
int main()
{
    vector<int> arr = {40, 10, 20, 30};

    vector<int> rank = arrayRankTransform(arr);

    cout << "[";
    for (int i = 0; i < rank.size(); i++)
    {
        cout << arr[i];
        if (i != rank.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}