#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arr[2*n]={0};
    char  brr[2*n];
   for(int i=0;i<2*n;i++)
     {
        cin>>brr[i];
        if(brr[i]=='-')
             cin>>arr[i];
     }
   priority_queue<int,vector<int>,greater<int>> q;
   int flag=0;
   vector<int> f;
   int num=1;
   for(int i=2*n-1;i>=0;i--)
     {
        if(brr[i]=='+')
           {
              if(q.empty())
                {
                   flag=1;
                   break;
                }
               else 
                 {
                    f.push_back(q.top());
                    q.pop();
                 }
           }
         else
          {
            int x=arr[i];
            q.push(x);
            if(x!=q.top())
              {
                 flag=1;
                 break;
              }
             
          }
     }
     if(f.size()<n||flag==1)
        cout<<"NO\n";
     else
      {
         cout<<"YES\n";
         for(int i=f.size()-1;i>=0;i--)
            cout<<f[i]<<" ";
         
      }
}