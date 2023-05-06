#include <bits/stdc++.h>
using namespace std;
int main()
{
 int arr[10],burst[10],i,tq=2,n,min1=1000,p,time=0,tt[10],wt[10],j,temp;
 printf("Enter number of processes: ");
 scanf("%d",&n);
 printf("Enter the arrival time and burst time of the processe: ");
 for(i=0;i<n;i++)
  scanf("%d%d",&arr[i],&burst[i]);
 for(i=0;i<n;i++)
  {
    if(arr[i]<min1)
      {
        min1=arr[i];
        p=i;
      }
  }
  //cout<<p<<endl;
 queue<int> q;
 q.push(p);
 int prev_time=min1;
 while(!q.empty())
  {
   temp=q.front();
   q.pop();
   if(burst[temp]>0 && burst[temp]<=tq)
     {
      time+=burst[temp];
      tt[temp]=time-arr[temp];
      for(i=prev_time;i<=time;i++)
        {
          for(j=0;j<n;j++)
            {
              if(arr[j]<=i && j!=p)
                 q.push(j);
            }
        }
       prev_time+=tq;
     }
   else if(burst[temp]>tq)
    {
      time+=tq;
      burst[temp]-=tq;
      for(i=prev_time;i<=time;i++)
        {
          for(j=0;j<n;j++)
            {
              if(arr[j]<=i && j!=p)
                 q.push(j);
            }
        }
       prev_time+=tq;
       q.push(p);
    }
  }
 for(int i=0;i<n;i++)
    wt[i]=tt[i]-burst[i];
  for(int i=0;i<n;i++)
    {
     cout<<"Waiting Time = "<<wt[i]<<" "<<"Turn Around Time = "<<tt[i]<<endl;
    }
}
