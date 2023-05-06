#include <bits/stdc++.h>
using namespace  std;

//function to find the spiral
//matrix of dimension n*n
vector<vector<int>> spiralMatrix(int n) 
{

    //value of the matrix from 1 to n*n
        int i=1;
        int k=0,l=0;
        int it;
        int m=n;

        //matrix for final output
        //initialize with 0
        vector<vector<int>> matrix( m , vector<int> (n, 0));
        //iterate till the end of rows and 
        //colums
        while(k<m&&l<n)
        {
          // get first row from the remaining
          //rows of the matrix
         for(it=l;it<n;it++)
            {
                matrix[k][it]=i;

                //increment to next value
                i++;
            }
           //increment row count from top
           //to down 
            k++;

            //generate the last column from
            //the remaining columns
            for(it=k;it<m;it++)
            {
                matrix[it][n-1]=i;

                //increment for next value
                i++;
            }

            //decrement no of rows
            n--;

            //if their are rows remaing
            if(k<m)
            {

                //generate the last row from the remaning
                //rows
                for(it=n-1;it>=l;it--)
                {
                    matrix[m-1][it]=i;
                    i++;
                }
            //decremenr no of colums
            m--;
            }

            //if thier is any column
            if(l<n)
            {

                //generate the first column
                //from the remaining columns
                for(it=m-1;it>=k;it--)
                {
                    matrix[it][l]=i;
                    i++;
                }
              l++;      
            }
        }
     //return the final result
        return matrix;
              
}

//function to print the matrix
void printMatrix(vector<vector<int>> matrix)
{

    //dimension of square matrix
    int n=matrix.size();

    //iterate till end of rows
    for(int i=0;i<n;i++)
      {

          //iterate till end of columns
          for(int j=0;j<n;j++)
            {
                //print the current cell value
                cout<<matrix[i][j]<<" ";
            }
        cout<<"\n";
      }
}
int main()
{
    // number of col, row
    int n = 3;
    // create spiral matrix
    vector<vector<int>> spiral = spiralMatrix(n);
    // print matrix
    printMatrix(spiral);
}