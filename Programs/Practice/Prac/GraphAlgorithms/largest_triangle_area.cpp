#include <bits/stdc++.h>
using namespace std;

double largestTriangleArea(vector<vector<int>> &p)
{
    double res = 0.0;
    int size = p.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                int x1 = p[i][0], y1 = p[i][1];
                int x2 = p[j][0], y2 = p[j][1];
                int x3 = p[k][0], y3 = p[k][1];

                double area = 0.5 * abs(x1 * (y2 - y3) +
                                        x2 * (y3 - y1) + x3 * (y1 - y2));

                res = max(res, area);
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0},
                                 {0, 2}, {2, 0}};

    cout << largestTriangleArea(points);

    return 0;
}