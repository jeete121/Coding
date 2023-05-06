#include <bits/stdc++.h>
using namespace std;

#define LINE "|"
#define NEWROW "-------------------------------------"

// Prints the Soduko grid
void printGrid(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << "    \n";
        cout << NEWROW << endl;
        for (int j = 0; j < 9; j++)
        {
            cout << " ";

            //empty cell of the grid
            if (grid[i][j] == 0)
            {
                cout << " ";
            }

            //otherwise print that
            else
            {
                cout << grid[i][j];
            }
            cout << " ";
            cout << LINE;
        }
    }
    cout << "\n"
         << NEWROW << "\n"
         << "\n";
}

//check for valid row by assigning value to any
//cell
bool isValidRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
        {
            return true;
        }
    return false;
}

//check for valid col by assigning value  by assigning
//any cell
bool isValidCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
        {
            return true;
        }
    return false;
}

//check if the box of 3x3 is valid ot not
bool isValidBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
            {
                return true;
            }
    return false;
}

//check whether it will be legal to assign
// num to the given row,col location.
bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Check if 'num' is not already placed in current row,
    // current column and current 3x3 box
    return !isValidRow(grid, row, num) &&
           !isValidCol(grid, col, num) &&
           !isValidBox(grid, row - row % 3, col - col % 3, num);
}

//check for empty cell
pair<int, int> getEmptyLocation(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            if (grid[row][col] == 0)
            {
                return make_pair(row, col);
            }
    return make_pair(9, 9);
}

//function to check if we can solve the sudoku
bool solveSudoku(int grid[9][9])
{
    // If the Soduko grid has been filled, we are done
    if (getEmptyLocation(grid) == make_pair(9, 9))
    {
        return true;
    }

    // Get an unassigned Soduko grid location
    std::pair<int, int> row_and_col = getEmptyLocation(grid);
    int row = row_and_col.first;
    int col = row_and_col.second;

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        //if by placing current value into
        //the current cell is valid then place it
        if (isSafe(grid, row, col, num))
        {
            //assign value to current cell
            grid[row][col] = num;

            //call recursively
            if (solveSudoku(grid))
            {
                return true;
            }
            //backtrack
            grid[row][col] = 0;
        }
    }
    //if not valid then return false;
    return false;
}
int main()
{

    int grid[9][9] = {{0, 9, 0, 0, 0, 0, 8, 5, 3},
                      {0, 0, 0, 8, 0, 0, 0, 0, 4},
                      {0, 0, 8, 2, 0, 3, 0, 6, 9},
                      {5, 7, 4, 0, 0, 2, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 9, 0, 0, 6, 3, 7},
                      {9, 4, 0, 1, 0, 8, 5, 0, 0},
                      {7, 0, 0, 0, 0, 6, 0, 0, 0},
                      {6, 8, 2, 0, 0, 0, 0, 9, 0}};

    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists for the given Soduko\n";
    }

    return 0;
}