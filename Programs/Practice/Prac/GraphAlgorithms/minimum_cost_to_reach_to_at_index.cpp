#include <bits/stdc++.h>
using namespace std;


//function to find the minimum cost
//to move chips 
int minCostToMoveChips(vector<int>& position) 
{
     int odd=0,even=0;

     //cout the odd and even 
     //elements in the array
     for(int i=0;i<position.size();i++)
      {
        if(position[i]&1)
              odd++;
        else
            even++;
      }
      //return the min of both
      return min(odd,even);
}
int main()
{
    vector<int> position ={2,2,2,3,3};
    cout<<minCostToMoveChips(position);
    return 0;
}


