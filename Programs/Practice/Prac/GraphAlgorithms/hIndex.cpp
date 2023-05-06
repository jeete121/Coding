#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{

    //sort the array in decresasing order
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++)
    {
        if (i >= citations[i])
        {
            return i;
        }
    }
    return citations.size();
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << hIndex(citations);
    return 0;
}