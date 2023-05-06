#include <bits/stdc++.h>
using namespace std;

//function to group the peoples
vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
{
        vector<pair<int,int>> v;
        for(int i=0;i<groupSizes.size();i++)
               v.push_back({groupSizes[i],i});

      //sort the vector pair array
       sort(v.begin(),v.end());
       vector<vector<int>> res;
       int i=0;
       int n=v.size();

        //iterate till the length of array
        while(i<n)
         {
            vector<int>x;
            int p=v[i].first-1;
            while(i+1<n&&v[i].first==v[i+1].first&&p>0) 
            {
                x.push_back(v[i].second);
                i++;
                p--;
                
            }
            x.push_back(v[i].second);
            i++;
            res.push_back(x);
         }
        return res;
}
int main()
{
    vector<int > groupSizes ={3,3,3,3,3,1,3};
    vector<vector<int>> group=groupThePeople(groupSizes);
    cout<<"[";
    for(int i=0;i<group.size();i++)
      {
          cout<<"[";
          for(int j=0;j<group[i].size();j++)
            {
                cout<<group[i][j];
                if(j!=group[i].size()-1)
                   cout<<",";
            }
            cout<<"]";
            if(i!=group.size()-1)
              cout<<",";
      }
     cout<<"]";
     return 0;
}
