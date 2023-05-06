#include <bits/stdc++.h>
using namespace std;



//function to check if row is valid or not
bool Row(vector<vector<char>> &board,int row)
{
    set<char> st;
    for(int i=0;i<9;i++)
        {
            if(st.find(board[row][i])!=st.end())
                  return false;
            if(board[row][i]!='.')
                   st.insert(board[row][i]);
       }
     return true;
}

//function to check if column is valid or not
bool Col(vector<vector<char>> &board,int col)
{
        set<char> st;
        for(int i=0;i<9;i++)
        {
            if(st.find(board[i][col])!=st.end())
                  return false;
            if(board[i][col]!='.')
                   st.insert(board[i][col]);
        }
        return true;
}

//function to check if box is valid
//or not
bool Box(vector<vector<char>> &board,int row,int col)
{
    set<char> st;
    for(int i=0;i<3;i++)
     {
        for(int j=0;j<3;j++)
            {
                char curr=board[i+row][j+col];
                if(st.find(curr)!=st.end())
                      return false;
                else if(curr!='.')
                       st.insert(curr);
            }
        }
        return true;
}
//function to check for the each row ,each column,each box of 3*3     
bool isValid(vector<vector<char>> &board,int row,int col)
{
    return Row(board,row)&&Col(board,col)&&Box(board,row-row%3,col-col%3);
}
bool isValidSudoku(vector<vector<char>>& board) 
{

    //iterate for all cells
    for(int i=0;i<9;i++)
      {
        for(int j=0;j<9;j++)
        {

            //if not valid then returnfalse
            if(!isValid(board,i,j))
                {
                     return false;
                }
        }
      }
  return true;
}

int main()
{
   vector<vector<char>> board= 
      {{'5','3','.','.','7','.','.','.','.'},
       {'6','.','.','1','9','5','.','.','.'},
       {'.','9','8','.','.','.','.','6','.'},
       {'8','.','.','.','6','.','.','.','3'},
       {'4','.','.','8','.','3','.','.','1'},
       {'7','.','.','.','2','.','.','.','6'},
       {'.','6','.','.','.','.','2','8','.'},
       {'.','.','.','4','1','9','.','.','5'},
       {'.','.','.','.','8','.','.','7','9'}};
   if(isValidSudoku(board))
      cout<<"true";
   else
    cout<<"false";
 
  return 0;
 
}