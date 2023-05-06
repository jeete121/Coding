#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int x, int y, int prevColor, int newColor)
{
    //check if current cell is valid or not
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size())
        return;

    //if current cell color is not same as the
    //prev color
    if (image[x][y] != prevColor)
        return;

    //if current cell color is same as new color
    if (image[x][y] == newColor)
        return;

    //update current cell color to new color
    image[x][y] = newColor;

    //call for down
    dfs(image, x + 1, y, prevColor, newColor);

    //call for up
    dfs(image, x - 1, y, prevColor, newColor);

    //call for right
    dfs(image, x, y + 1, prevColor, newColor);

    //call for left
    dfs(image, x, y - 1, prevColor, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int prevColor = image[sr][sc];
    dfs(image, sr, sc, prevColor, newColor);
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    image = floodFill(image, sr, sc, newColor);
    cout << "[";
    for (int i = 0; i < image.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < image[i].size(); j++)
        {
            cout << image[i][j];
            if (j != image[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != image.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}