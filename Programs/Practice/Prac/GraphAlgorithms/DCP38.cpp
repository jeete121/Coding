#include <bits/stdc++.h>
using namespace std;
int nQueens(int n, vector<int> &board)
{
    if (n == board.size())
        return 1;

    int count = 0;
    for (int col = 0; col < n; col++)
    {
        board.push_back(col);
        if (is_valid(board))
        {
            count += nQueens(n, board);
        }
        board.pop_back();
    }
    return count;
}
bool is_valid(vector<int> &board)
{
    int current_queen_row=board.size()-1;
    int  current_queen_col = board[current_queen_row];
#Check if any queens can attack the last queen.
    for row, col in enumerate(board[:-1]):
        diff = abs(current_queen_col - col)
        if diff == 0 or diff == current_queen_row - row:
            return False
    return True
}