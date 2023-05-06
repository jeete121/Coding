#include <bits/stdc++.h>
using namespace std;

vector<int> distributeCandies(int candies, int num_people)
{

    vector<int> res(num_people);
    for (int i = 0; candies > 0; candies -= i)
    {
        res[i % num_people] += min(i + 1, candies);
        i++;
    }
    return res;
}
int main()
{
    int candies = 7, num_people = 4;

    vector<int> res = distributeCandies(candies, num_people);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}