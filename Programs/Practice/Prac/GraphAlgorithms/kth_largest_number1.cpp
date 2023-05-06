#include <bits/stdc++.h>
using namespace std;

//function to find the kth
//largest number in an array
int findKthLargest(int nums[], int n,int k) 
 {

  //min priority queue
   priority_queue<int,vector<int>,greater<int> > pq;
   //push k elements into the priority queue
   for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

    for (int i = k; i <n; i++) 
      {
            if (nums[i] > pq.top() )
            {
                // replacing with root if new value is large
                pq.pop();
                pq.push(nums[i]);
            }
        }
        // out of k values it will return largest value
        return pq.top();

}
int main()
{
    int nums[] = { 3, 2, 1, 5, 6, 4 };
    int n=sizeof(nums)/sizeof(nums[0]);
    int k = 2;
    cout<<findKthLargest(nums, n,k)<<"\n";
    return 0;
}

 
