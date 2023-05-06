#include <bits/stdc++.h>
using namespace std;


//function to find the sum
//of array elements
int sumOfArray(int arr[],int n)
{
    //varible to hold
    //the sum
    int sum=0;

    //iterate till the size of array
    for(int i=0;i<n;i++)
       sum+=arr[i];
    
   //return the sum
   return sum;
}
//function to find the average
//of the given array
double  averageOfArray(int arr[],int n)
{
    int sum=sumOfArray(arr,n);
    double average=(double)sum/n ;
    return average;
}

int main()
{
    int arr[]={3,1,4,2,5,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=sumOfArray(arr,n);
    double average=averageOfArray(arr,n);

    cout<<"Sum is "<<sum<<", ";

    cout<<"Average is "<<average<<"\n";
}