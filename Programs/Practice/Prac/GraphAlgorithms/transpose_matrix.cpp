#include <bits/stdc++.h>
using namespace std;
//Function to find the transpose of matrix
void transposeMatix(int matrixA[][3],int n,int m)
{
   int matrixB[m][n];
   for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
             matrixB[j][i]=matrixA[i][j];
     } 
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
               cout<<matrixB[i][j]<<" ";
            cout<<"\n";
        }
}
int main()
{
    //matrix input
    int matrxixA[][3]={{6,2,3},{4,3,2},{4,5,7}};
    int n=3,m=3;
    transposeMatix(matrxixA,n,m);
}
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)