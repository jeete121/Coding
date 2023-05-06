#include <bits/stdc++.h>
using namespace std;

int heightChecker(vector<int> &heights)
{
    vector<int> a;
    a = heights;
    int cnt = 0;

    //sort the array
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        if (a[i] != heights[i])
            cnt++;
    return cnt;
}

int main()
{
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << heightChecker(heights);
    return 0;
}