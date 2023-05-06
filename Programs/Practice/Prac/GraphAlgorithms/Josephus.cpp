#include <bits/stdc++.h>
using namespace std;

//function for josephus
//problem
int josephus(int n,int k)
{

    //base case
    if(n==1)
       return 1;

     //call by killing kth person
     //in circle and decrese n by 1 
    return (josephus(n-1,k)+k-1)%n+1;
}
int main()
{
    int n=5,k=3;
    cout<<"Safe Position is\n";
    cout<<josephus(n,k)<<"\n";
    return 0;
}