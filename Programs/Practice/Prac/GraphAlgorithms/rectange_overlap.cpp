#include <bits/stdc++.h>
using namespace std;

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    return min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) 
        && min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
}

int main()
{
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    if (isRectangleOverlap(rec1, rec2))
        cout << "true";
    else
        cout << "false";

    return 0;
}