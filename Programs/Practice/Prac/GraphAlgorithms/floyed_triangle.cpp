#include <bits/stdc++.h>
using namespace std;


//function to generate the floyed
//triangle
vector<vector<int>> floyedTriangle(int n)
{
  vector<vector<int>> floyed;
  int num=1;
  for(int i=1;i<=n;i++)
    {
        vector<int> x;
        for(int j=1;j<=i;j++)
           x.push_back(num++);
        floyed.push_back(x);
    }
  return floyed;
}
int main()
{
    int n=3;
    vector<vector<int>> floyed=floyedTriangle(n);
    for(int i=0;i<floyed.size();i++)
       {
           for(int j=0;j<floyed[i].size();j++)
              cout<<floyed[i][j]<<" ";
          cout<<"\n";
       }
    return 0;
}