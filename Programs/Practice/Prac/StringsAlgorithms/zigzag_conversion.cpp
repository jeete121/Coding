#include <bits/stdc++.h>
using namespace std;


//function to convert the given
//string into the zigzag fashion
string convert(string s, int numRows) 
{
        int n=s.size();
        if(numRows==1)
              return s;
        int k=0,up=0,r=0;
        string res="",ans[n];
        while(k<n)
         {
             //move up
            if(up==0)
            {
                while(k<n&&r<numRows)
                {
                    ans[r++]+=s[k++];
                }
              up=1;
              r=numRows-2;
            }

         //move down
          else
          {
              while(k<n && r>=0)
              {
                  ans[r--]+=s[k++];
              }
             up=0;
              r=1;
                   
          }
         }
        for(int i=0;i<n;i++)
               res+=ans[i];
        return res;
}
int main()
{
  string str = "PAYPALISHIRING";
  int numRows = 3;
  cout<<convert(str,numRows);
  return 0;
}


