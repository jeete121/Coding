#include <bits/stdc++.h>
using namespace std;


bool isValid(int x,int y,int n,int m)
{
    if(x<0||x>=n||y<0||y>=m)
        return false;
    return true;
    
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(vector<vector<char>> &board,int x,int y,char prevc ,char newc)
{
       if(x<0 ||x>=board.size()||y<0||y>=board[0].size()) 
             return;
       if(board[x][y]!=prevc)
             return;
       board[x][y]=newc;
       for(int i=0;i<4;i++)
         {
             if(isValid(dx[i]+x,dy[i]+y,board.size(),board[0].size()))
                {
                    dfs(board,dx[i]+x,dy[i]+y,prevc,newc);
                }
         }
}
void solve(vector<vector<char>>& board) 
{
    int n=board.size();

    //if empty grid
    if(n==0)
        return ;
    int m=board[0].size();
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')  
                       board[i][j]='-';
            }
        }
      for (int i=0; i<n; i++)
            {
                if (board[i][0] == '-') 
                {
                    
                       dfs(board, i, 0, '-', 'O'); 
                }
            }
            for (int i=0; i<n; i++)
            {
                if (board[i][m-1] == '-')
                {
                    
                           dfs(board, i, m-1, '-', 'O'); 
                }
            }
            for (int i=0; i<m; i++)
                  if (board[0][i] == '-') 
                      dfs(board, 0, i, '-', 'O'); 
             for (int i=0; i<m; i++)
             {
                 
                       if (board[n-1][i] == '-') 
                       {
                           
                          dfs(board, n-1, i, '-', 'O');
                       }
             }
                for (int i=0; i<n; i++) 
                {
                        for (int j=0; j<m; j++) 
                        {
                                   if (board[i][j] == '-') 
                                   {
                                         board[i][j] = 'X'; 
                                   }
                        }
                }
}
int main()
{
    vector<vector<char>> board={{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};
    solve(board);
    cout<<"[";
    for(int i=0;i<board.size();i++)
      {
          cout<<"[";
          for(int j=0;j<board[i].size();j++)
            {
                cout<<board[i][j];
                if(j!=board[i].size()-1) 
                  cout<<",";
            }
            if(i!=board.size()-1)
              cout<<"],\n";
            else
            cout<<"]";
            
      }
      cout<<"]";
}


