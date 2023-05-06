#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<bool>> &board,
             int M, int N,
             vector<vector<bool>> visited,
             int i, int j)
{
    return !(i < 0 || j < 0 || i >= M || j >= N ||
             !board[i][j] || visited[i][j]);
}

int ShortestPathInAMaze(vector<vector<bool>> &board,
                        int srcX, int srcY,
                        int destX, int destY)
{
    int M = board.size();
    int N = M > 0 ? board[0].size() : 0;

    vector<vector<bool>> visited(M, vector<bool>(N, false));

    queue<vector<int>> q;

    if (isValid(board, M, N, visited, srcX, srcY))
    {
        q.push({srcX, srcY, 0});
        visited[srcX][srcY] = true;
    }

    while (!q.empty())
    {
        vector<int> tempElement = q.front();
        q.pop();

        if (tempElement[0] == destX && tempElement[1] == destY)
        {
            return tempElement[2];
        }

        // checking if the 4 elements are valid or
        //not and pushing in the queue

        if (isValid(board, M, N,
                    visited, tempElement[0] + 1, tempElement[1]))
        {
            q.push({tempElement[0] + 1, tempElement[1],
                    tempElement[2] + 1});
        }

        if (isValid(board, M, N, visited,
                    tempElement[0] - 1, tempElement[1]))
        {
            q.push({tempElement[0] - 1, tempElement[1],
                    tempElement[2] + 1});
        }

        if (isValid(board, M, N, visited,
                    tempElement[0], tempElement[1] + 1))
        {
            q.push({tempElement[0], tempElement[1] + 1,
                    tempElement[2] + 1});
        }

        if (isValid(board, M, N, visited,
                    tempElement[0], tempElement[1] - 1))
        {
            q.push({tempElement[0], tempElement[1] - 1,
                    tempElement[2] + 1});
        }
    }

    // -1 indicates no path exists.
    return -1;
}

int main()
{
    vector<vector<bool>> board = {{1, 1, 1, 1},
                                  {0, 0, 1, 0},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 1}};

    int srcX = 3, srcY = 0;
    int destX = 0, destY = 0;
    cout << ShortestPathInAMaze(board, srcX, srcY, destX, destY);

    return 0;
}