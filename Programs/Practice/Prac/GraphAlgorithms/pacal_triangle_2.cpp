#include <bits/stdc++.h>
using namespace std;


//function to get the nth row of 
//pascal triangle 
vector<int> getRow(int rowIndex)
{
    vector<vector<int>> v;
    for(int line=0;line<=rowIndex;line++)
         {
            vector<int> x;
           for(int i=0;i<=line;i++)
            {
              if(line==i||i==0)
                  x.push_back(1);
               else
                  x.push_back(v[line-1][i-1]+v[line-1][i]);
            }
            v.push_back(x);
         }
    vector<int> res;

    //find the nth row of the pascal triangle
    for(int i=0;i<v[rowIndex].size();i++)
        res.push_back(v[rowIndex][i]);
    return res;
}
int main()
{
    int n=3;
    vector<int> row=getRow(n);
    for(int i=0;i<row.size();i++)
       cout<<row[i]<<" ";
    return 0;
}
