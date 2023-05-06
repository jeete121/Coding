#include <bits/stdc++.h>
using namespace std;

//function to rotate the image
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    for (int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            swap(matrix[i][end], matrix[i][start]);
            start++;
            end--;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    cout << "[";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j];
            if (j != matrix[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != matrix.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}