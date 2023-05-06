#include <bits/stdc++.h>
using namespace std;
//function to add two given matrix
void addMatrix(int arr[][3],int brr[][3],int n,int m)
{
    for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
            {
                //store the final result
                //in first matrix
                arr[i][j]=arr[i][j]+brr[i][j];
            }
     }
}
int main()
{
    //first matrix
    int arr[][3]={{6,2,3},{4,3,2},{4,5,7}};
    //second matrix
    int brr[][3]={{4,6,2},{2,6,1},{1,5,1}};
    int n=3,m=3;
    addMatrix(arr,brr,n,m);
    cout<<"Result after add is\n";
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
             cout<<arr[i][j]<<" ";
        cout<<"\n";
      }
    return 0;
}
//Time Complexity:O(n^2)
