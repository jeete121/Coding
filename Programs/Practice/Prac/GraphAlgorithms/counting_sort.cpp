#include <bits/stdc++.h>
using namespace std;

//function to sort the array
//using counting sort
void counting_sort(int arr[],int N)
{
    int MAXN=0;

    //find the maximum element
    //in the array
    for(int i=0;i<N;i++)
       MAXN=max(MAXN,arr[i]);

    //make the array of size maximum element +1
    int freq[MAXN+1];
    for(int i=0;i<=MAXN;i++)
      freq[i]=0;

    //count the frequency of each
    //element
    for(int i=0;i<N;i++)
      freq[arr[i]]++;
    int index=0;

    //sort the array on the basis
    //of the counts
    for(int i=0;i<=MAXN;i++)
      {

          while(freq[i]>0)
            {
                arr[index++]=i;
                freq[i]--;
            }
      }
    
}
int main()
{
    int arr[]={3,2,4,4,3,1};
    int N=sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr,N);
    for(int i=0;i<N;i++)
       cout<<arr[i]<<" ";
    return 0;
}