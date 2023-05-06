#include <bits/stdc++.h>
using namespace std;


//function to find the maximum profit 
//we can get after putting all elements whose
//capacity of weight is less then or equal to capacity
int knapSack(vector<int> profit,vector<int> weight,int capacity,int n)
{

    //base case if their is no elements
    //or capacity is zero then return 0
    if(n==-1||capacity==0)
       return 0;

    //if the weight of current element is 
    //greater than the value of the remaining 
    //capacity then ignore the current element
    if(weight[n]>capacity)
       return knapSack(profit,weight,capacity,n-1);

    //else the answer will we max after including
    //the current element or by excluding the current element
    else
      return max(knapSack(profit,weight,capacity,n-1),
          profit[n]+knapSack(profit,weight,capacity-weight[n],n-1));
}
int main()
{
    vector<int> profit={3,4,5,2,6,7};
    vector<int> weight={1,3,4,2,5,8};
    int capacity=13;

    cout<<knapSack(profit,weight,capacity,profit.size()-1);

    return 0;
    
}

