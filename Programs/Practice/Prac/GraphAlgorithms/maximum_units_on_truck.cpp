#include <bits/stdc++.h>
using namespace std;

//compartor to sort the array 
//in which order we wnad to sort the array
static bool cmp(vector<int> a,vector<int> b)
{
        if(a[1]==b[1])
              return a[0]>b[0];
        return a[1]>b[1];
}

//function to find the maximum units 
//on the truck
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{

    // sort the boxtypes
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++)
          {

              //if truckSize is less than bixTypes
              //then update answer and break
              if(truckSize<=boxTypes[i][0]) 
              {
                  ans=ans+truckSize*boxTypes[i][1];
                  break;
              }
            //else update answer and 
            //decrease the trucksize
             else
             {
                 ans=ans+boxTypes[i][0]*boxTypes[i][1];
                 truckSize-=boxTypes[i][0];
             }
          }
    //return the final answer
        return ans;
        
}
int main()
{
   vector<vector<int>> boxTypes ={{1,3},{2,2},{3,1}};
   int truckSize = 4;
   cout<<maximumUnits(boxTypes,truckSize);
   return 0;
}
