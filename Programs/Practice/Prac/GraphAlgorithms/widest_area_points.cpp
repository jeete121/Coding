#include <bits/stdc++.h>
using namespace std;

//comparator used for sorting
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
int maxWidthOfVerticalArea(vector<vector<int>> &points)
{

    //sort the array
    sort(points.begin(), points.end(), cmp);
    int ans = 0;

    //iterate till the length of array
    for (int i = 0; i < points.size() - 1; i++)
    {
        //update answer
        ans = max(ans, points[i + 1][0] - points[i][0]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    cout << maxWidthOfVerticalArea(points);
    return 0;
}