#include <bits/stdc++.h>
using namespace std;

int busyStudent(vector<int>& startTime, 
      vector<int>& endTime, int queryTime) 
{
    int n=startTime.size(),cnt=0;
    for(int i=0;i<n;i++)
       {
         if(queryTime>=startTime[i]&&queryTime<=endTime[i])
                     cnt++;
       }
     return cnt;
}
int main()
{
  vector<int> startTime ={1,2,3};
  vector<int> endTime = {3,2,7};
  int queryTime = 4;
  int busy=busyStudent(startTime,endTime,queryTime);
  cout<<busy<<"\n";
  return 0;
}

