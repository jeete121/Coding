#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
int dfs(int start,int end)
{
    //base case
    if(start>end)
        return 1;
    int ans=0;

    //iterate for all values
    for(int i=1;i<=end;i++)
        {
            if(vis[i]==0&&(i%start==0||start%i==0))
            {
                vis[i]=1;
                ans+=dfs(start+1,end);
                vis[i]=0;
            }
        }
        return ans;
}

int countArrangement(int n) 
{
        
        vis.resize(n+1);
        vis.clear();
        int ans=dfs(1,n);
        return ans;
}

int main()
{
    int n=2;
    cout<<countArrangement(n);
    return 0;
}