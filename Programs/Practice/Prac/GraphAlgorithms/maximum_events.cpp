#include <bits/stdc++.h>
using  namespace std;

//comparator used for sorting
static bool cmp(vector<int> &a,vector<int> &b)
{
        if(a[1]==b[1])
              return a[0]<b[0];
        return a[1]<b[1];
}

//function to count the events
int maxEvents(vector<vector<int>>& events)
{
        sort(events.begin(),events.end(),cmp);
        int n=events.size();
        int cnt=0;
        int start=0,temp=0;
        bool vis[events[n-1][1]+1];
        memset(vis,false,sizeof(vis));

        //itearte for all events
        for(int i=0;i<n;i++)
         {
           if(i>0&&events[i][0]==events[i-1][0])
           {
               start=temp;
           }
            else
                start=events[i][0];
            for(int j=start;j<=events[i][1];j++)
            {
                if(vis[j]==false)
                {
                    temp=j;
                    cnt++;
                    vis[j]=true;
                    break;
                }
            }
         }
        return cnt;
}

int main()
{
    vector<vector<int>> events ={{1,2},{2,3},{3,4}};
    cout<<maxEvents(events);
    return 0;
}
