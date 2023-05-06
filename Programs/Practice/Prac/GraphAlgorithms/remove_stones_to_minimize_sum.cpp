#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{

    priority_queue<int> q;

    for (int i = 0; i < piles.size(); i++)
        q.push(piles[i]);

    while (k > 0 && q.size() > 0)
    {
        int x = q.top();
        if (x > 1)
        {
            q.pop();

            q.push((x + 1) / 2);
        }
        k--;
    }
    int sum = 0;
    while (!q.empty())
    {
        sum += q.top();
        q.pop();
    }
    return sum;
}
int main()
{
    vector<int> piles = {5, 4, 9};
    int k = 2;

    cout << minStoneSum(piles, k) << "\n";

    return 0;
}