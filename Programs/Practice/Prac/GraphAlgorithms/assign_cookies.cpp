#include <bits/stdc++.h>
using namespace std;


int findContentChildren(vector<int>& g, 
  vector<int>& s) {

      //sort both the arrays
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size(),m=s.size();
        int i=0,k=0,cnt=0;
        while(k<m)
        {
            if(s[k]>=g[i])
             {
               cnt++;
                k++;
                i++;
              if(i==n)
                  break;
             }
            else
                k++;
         }
         return cnt;    
}
int main()
{
   vector<int>g = {1,2,3}, s ={1,1};
   cout<<findContentChildren(g,s);
   return 0;
}

