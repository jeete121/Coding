#include <bits/stdc++.h>
using namespace std;

//function to check the given
//matrix is identity or not
bool isIdentity(int matrix[][3],int n)
{
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
            {
                // if i==j and matrix[i][j]!=1
                //then return false
                if(i==j)
                  {
                      if(matrix[i][j]!=1)
                         return false;
                  }
                //else if i!=j and matrix[i][j]!=0
                //then return false
                else
                {
                    if(matrix[i][j]!=0)
                        return false;
                }
                
            }
      }
    return true;
}
int main()
{
    //given input matrix as square 
    //matrix
    int matrix[][3]={{1,0,0},{0,1,0},{0,0,1}};
    int n=3;
    if(isIdentity(matrix,n))
       cout<<"Identity\n";
    else
      cout<<"Not Identity\n";
}