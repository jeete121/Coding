#include <bits/stdc++.h>
using namespace std;

//function tom generate the pascal triangle
//of given number of rows
vector<vector<int>> pascalTriangle(int numRows) 
{
    //store the final result
    vector<vector<int>> res;
        for(int i=0;i<numRows;i++)
        {
            vector<int> v;


            for(int j=0;j<=i;j++)
            {

                //base case if last or first
                if(j==0||j==i)
                      v.push_back(1);
                //else sum of previous two 
                else
                    v.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res.push_back(v);
        }
        return res;
}
int main()
{
   int n=5;
   vector<vector<int>> pascal=pascalTriangle(n);
   cout<<"[\n";
   for(int i=0;i<pascal.size();i++)
     {
         cout<<"[";
         for(int j=0;j<pascal[i].size();j++)
           {
               if(j==pascal[i].size()-1)
                  cout<<pascal[i][j];
               else
                 cout<<pascal[i][j]<<",";
           }
           cout<<"]";
           if(i!=pascal.size()-1)
             cout<<",";
        cout<<"\n";
     }
     cout<<"]";
}