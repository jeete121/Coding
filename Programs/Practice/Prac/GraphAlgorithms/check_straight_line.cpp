#include <bits/stdc++.h>
using namespace std;

//function to check if all points
//form a single line
bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int n = coordinates.size();
    float slop = 0, c;
    //find the slope
    if ((coordinates[n - 1][0] - coordinates[0][0]) != 0)
        slop = (float)(coordinates[n - 1][1] - coordinates[0][1]) / (coordinates[n - 1][0] - coordinates[0][0]);
    c = coordinates[0][1] - coordinates[0][0] * slop;
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
        if (coordinates[i][0] != coordinates[i + 1][0])
        {
            flag = 1;
            break;
        }
    if (flag == 0)
        return true;
    for (int i = 1; i < coordinates.size() - 1; i++)
    {
        float a = coordinates[i][1] - coordinates[0][1];
        float b = coordinates[i][0] - coordinates[0][0];
        if ((float)(a / b) != slop)
            return false;
    }
    return true;
}
int main()
{
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    if (checkStraightLine(coordinates))
        cout << "true";
    else
        cout << "false";
    return 0;
}