#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> &candies)
{
    unordered_map<int, int> ump;
    int n = candies.size();
    for (int i = 0; i < n; i++)
        ump[candies[i]]++;
    int num = ump.size();
    if (num >= n / 2)
        return n / 2;
    else
        return num;
}

int main()
{
    vector<int> candyType = {1, 1, 2, 2, 3, 3};

    cout << distributeCandies(candyType);

    return 0;
}