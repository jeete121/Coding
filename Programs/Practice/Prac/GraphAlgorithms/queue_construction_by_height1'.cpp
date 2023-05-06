#include <bits/stdc++.h>
using namespace std;

//comparator used to sort the array
static bool cmp(vector<int> a ,vector<int> b)
{
        if(a[0]==b[0])
              return a[1]<b[1];
        else
            return a[0]>b[0];
}

//function to reconstruct the queue
vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res;
       if(people.size()==0)
            return res;
        for(int i=0;i<people.size();i++)
              res.insert(res.begin()+people[i][1],people[i]);
        return res;
}

int main()
{
    vector<vector<int>> people ={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    people=reconstructQueue(people);
    cout<<"[";
    for(int i=0;i<people.size();i++)
      {
          
          cout<<"["<<people[i][0]<<" "<<people[i][1]<<"]";
          if(i!=people.size()-1)
            cout<<",";
      }
      cout<<"]";
      return 0;
}