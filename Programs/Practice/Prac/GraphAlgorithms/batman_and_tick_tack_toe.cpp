#include <bits/stdc++.h>
using namespace std;

vector<string> board;
bool row()
{
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (board[i][j] == 'x' &&
                board[i][j + 1] == 'x' &&
                board[i][j + 2] == '.')
            {
                flag = 1;
                break;
            }
            if (board[i][j] == '.' &&
                board[i][j + 1] == 'x' &&
                board[i][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
            if (board[i][j] == 'x' &&
                board[i][j + 1] == '.' &&
                board[i][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return true;
    return false;
}

bool col()
{
    bool flag = false;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <= 1; i++)
        {
            if (board[i][j] == 'x' &&
                board[i + 1][j] == 'x' &&
                board[i + 2][j] == '.')
            {
                flag = 1;
                break;
            }

            if (board[i][j] == 'x' &&
                board[i + 1][j] == '.' &&

                board[i + 2][j] == 'x')
            {
                flag = 1;
                break;
            }

            if (board[i][j] == '.' &&
                board[i + 1][j] == 'x' &&
                board[i + 2][j] == 'x')
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return true;
    return false;
}

bool diagonal()
{
    bool flag = false;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (board[i][j] == 'x' &&
                board[i + 1][j + 1] == 'x' &&
                board[i + 2][j + 2] == '.')
            {
                flag = 1;
                break;
            }
            if (board[i][j] == '.' &&
                board[i + 1][j + 1] == 'x' &&
                board[i + 2][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
            if (board[i][j] == 'x' &&
                board[i + 1][j + 1] == '.' &&
                board[i + 2][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
            if (board[i + 2][j] == 'x' &&
                board[i + 1][j + 1] == 'x' &&
                board[i][j + 2] == '.')
            {
                flag = 1;
                break;
            }
            if (board[i + 2][j] == 'x' &&
                board[i + 1][j + 1] == '.' &&
                board[i][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
            if (board[i + 2][j] == '.' &&
                board[i + 1][j + 1] == 'x' &&
                board[i][j + 2] == 'x')
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        return true;
    return false;
}

int main()
{

    board = {{"xx.."},
             {".oo."},
             {"x..."},
             {"oox."}};

    bool ans1 = row(), ans2 = col(), ans3 = diagonal();
    if (ans1 == true || ans2 == true || ans3 == true)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}