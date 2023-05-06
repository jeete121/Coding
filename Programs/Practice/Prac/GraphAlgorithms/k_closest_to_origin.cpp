#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
        vector<vector<int>> res;
        int n=points.size();
        vector< pair<int, vector<int> >> myvec; 
        for(auto i:points)
        {
            int x=i[0]*i[0]+i[1]*i[1];
            myvec.push_back(make_pair(x,i));
        }
        sort(myvec.begin(),myvec.end());
        for(int i=0;i<K;i++)
              res.push_back(myvec[i].second);
        return res;
}

int main()
{
    vector<vector<int>> points ={{1,3},{-2,2}};
    int  K = 1;
    vector<vector<int>> point= kClosest(points,K);
    cout<<"[";
    for(int i=0;i<point.size();i++)
      {
          cout<<"[";
          for(int j=0;j<point[i].size();j++)
           {
               cout<<point[i][j];
               if(j!=point[i].size()-1)
                 cout<<",";
           }
         cout<<"]";
          if(i!=point.size()-1)
            cout<<",";
      }
    cout<<"]";
    return 0;
}