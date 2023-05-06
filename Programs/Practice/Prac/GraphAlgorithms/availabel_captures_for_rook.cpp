#include <bits/stdc++.h>
using namespace std;

int numRookCaptures(vector<vector<char>> &board)
{
    int x, y;
    bool flag = false;
    int r = board.size();
    int c = board[0].size();

    // find the position of rook
    //on the board
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            //if current position
            //on the board is rook
            //then store the x coordinates
            //y coordinate and break
            if (board[i][j] == 'R')
            {
                x = i;
                y = j;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    int cnt = 0;
    bool B = false, P = false;
    // iterate x direction and find proper pawns
    for (int i = 0; i < c; i++)
    {
        if (i <= y)
        {

            //if pawns found
            if (board[x][i] == 'p')
                P = true;
            if (board[x][i] == 'B' && P)
                P = false;
            if (i == y && P)
            {
                cnt++;
                P = false;
            }
        }
        else
        {
            if (board[x][i] == 'B')
                B = true;
            if (board[x][i] == 'p' && !B)
                P = true;
            if (i == c - 1 && P)
            {
                cnt++;
            }
        }
    }
    // iterate in y direction and find the proper pawns
    B = false, P = false;
    for (int i = 0; i < r; i++)
    {
        if (i <= x)
        {
            if (board[i][y] == 'p')
                P = true;
            if (board[i][y] == 'B' && P)
                P = false;
            if (i == x && P)
            {
                cnt++;
                P = false;
            }
        }
        else
        {
            if (board[i][y] == 'B')
                B = true;
            if (board[i][y] == 'p' && !B)
                P = true;
            if (P && i == r - 1)
            {
                cnt++;
            }
        }
    }
    // a little long but so fast ...
    return cnt;
}

int main()
{
    vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.'}};

    cout << numRookCaptures(board);

    return 0;
}