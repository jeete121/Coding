#include <bits/stdc++.h>
using namespace std;


int minDeletionSize(vector<string>& A)
{
       vector<int> D;
      int len=A[0].size();
      for(int j=0;j<len;j++)
      {
         int flag=0;
       for(int i=0;i<A.size()-1;i++)
        {
           if(A[i][j]>A[i+1][j])
           {
               flag=1;
               break;
           }
        }
          if(flag==1)
                D.push_back(j);
      }
        return D.size();
}
int main()
{
    vector<string> str ={"cba","daf","ghi"};
    cout<<minDeletionSize(str);
    return 0;
}
