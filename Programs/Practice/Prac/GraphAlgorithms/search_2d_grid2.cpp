#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (binary_search(matrix[i].begin(), matrix[i].end(), target))
            return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                 {10, 11, 16, 20},
                                 {23, 30, 34, 60}};

    int target = 3;
    if (searchMatrix(matrix, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}