#include <bits/stdc++.h>
using namespace std;

void sortArrayOrder(vector<int> &A, vector<int> &B)
{
    map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
    {
        mp[A[i]]++;
    }
    int index = 0;
    for (int i = 0; i < B.size(); i++)
    {
        while (mp[B[i]])
        {
            A[index] = B[i];
            mp[B[i]]--;
            index++;
        }
        mp.erase(B[i]);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        while (it->second--)
        {
            A[index] = it->first;
            index++;
        }
    }
}
int main()
{
    vector<int> A = {5, 8, 1, 5, 7, 1, 3, 4, 9, 4};

    vector<int> B = {3, 5, 7, 2};

    sortArrayOrder(A, B);
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}