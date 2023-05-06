#include <bits/stdc++.h>
using namespace std;

//comparator used to sort the array
static bool cmp(vector <int> a, vector <int> b)
{
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
}
int twoCitySchedCost(vector<vector<int>>& costs) 
{
        int n=costs.size();
        int ans=0;
        int cnt1=n/2,cnt2=n/2;

        sort(costs.begin(),costs.end(),cmp);
        for(int i=0;i<n;i++)
        {
            if(cnt2==0||(costs[i][0]<costs[i][1]&&cnt1>0))
            {
                cnt1--;
                ans+=costs[i][0];
            }
          else
          {
              cnt2--;
             ans+= costs[i][1];
          }
        }
        return ans;
}
int main()
{
    vector<vector<int>>  costs ={{10,20},{30,200},
                                {400,50},{30,20}};
    cout<<twoCitySchedCost(costs);
    return 0;
}