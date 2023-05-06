#include <bits/stdc++.h>
using namespace std;

//function to find the last stone
//weight
int lastStoneWeight(vector<int>& stones) 
{

    //make priority queue of all stones
    priority_queue <int> q(stones.begin(), stones.end());

    //iterate till the priority queue size is
    //greater than 1
    while(q.size()>1)
    {

            //pop top 2 elements
            int x = q.top();
            q.pop();
            int y = q.top(); 
            q.pop();

            //push the absoulute value diff
            //of both the elements
            q.push(abs(x-y));
     }
  //return the top of
  //priority queue
   return q.top();
}
int main()
{
    vector<int> stones={2,7,4,1,8,1};
    cout<<lastStoneWeight(stones);
    return 0;

}

