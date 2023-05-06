#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
{
      for(int i=0;i<A.size();i++)
            reverse(A[i].begin(),A[i].end());
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
                   A[i][j]=!A[i][j];
        }
     return A;
}
int main()
{
    vector<vector<int>> A={{1,1,0},{1,0,1},{0,0,0}};
    A=flipAndInvertImage(A);
  cout<<"[";
    for(int i=0;i<A.size();i++)
       {
           cout<<"[";
           for(int j=0;j<A[0].size();j++)
             {
               cout<<A[i][j];
               if(j!=A[0].size()-1)
                   cout<<",";   
             }
             cout<<"]";
            if(i!=A.size()-1)
              cout<<",";
       }
    cout<<"]";
}

