#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
   vector<vector<int>> v;
    int lastAnswer=0;
    for(int i=0;i<q;i++)
        {
          int z,x,y;
          cin>>z>>x>>y;
          
          if(z==1)
             {
                 
                 int p=(x^lastAnswer)%n;
                 v[p].push_back(y);
             }
          else if(z==2)
              {
                  int p=(x^lastAnswer)%n;
                  lastAnswer=(y%(v[p].size()));
                  cout<<lastAnswer<<endl;
              }
        }
    return 0;
}