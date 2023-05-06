#include <bits/stdc++.h>
using namespace std;

//resaphe the matrix into the new 
//dimensions
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, 
   int r, int c)
{
       vector<vector<int>> v;
      int n=nums.size();
        int m=nums[0].size();
        //if new dimensions are not match 
        //then return the original matrix
        if(n*m!=r*c)
              return nums;
        else
        {
             vector<int> p;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    p.push_back(nums[i][j]);
                }
            }
            vector<int> x;
            for(int i=0;i<p.size();i++)
            {
                x.push_back(p[i]);
                if(x.size()==c)
                {
                    v.push_back(x);
                    x.clear();
                }
            }
             return v;
        }
       
}
int main()
{
    vector<vector<int>> nums = {{1,2},
                               {3,4}};
    int r = 1, c = 4;

    vector<vector<int>> res=matrixReshape(nums,r,c);
    cout<<"[";
    for(int i=0;i<r;i++)
      {
          cout<<"[";
         for(int j=0;j<c;j++)
           {
               if(j!=c-1)
                  cout<<res[i][j]<<",";
               else
                  cout<<res[i][j];
               
           }
         if(i!=r-1)
            cout<<"],";
         else
           cout<<"]";
      }
     cout<<"]";
}

