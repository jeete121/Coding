#include <bits/stdc++.h>
using namespace std;
long long int merge(long long int arr[], long long int temp[], long long int left,long long int mid, long long int right)
{
	long long int i, j, k;
	long long int inv_count=0;
	i=left;
	j=mid;
	k=left;
	while ((i <= mid - 1) && (j <= right))
    {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else 
      {
			temp[k++] = arr[j++];
			inv_count+=(mid - i);
		}
	 }
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}
long long int count_Inversion(long long int arr[], long long int temp[], long long int left, long long int right)
{
	long long int  mid ,inv_count = 0;
	if (right > left) 
   {
		 mid = (right+left)/2;
		inv_count+=count_Inversion(arr,temp,left,mid);
		inv_count+=count_Inversion(arr,temp,mid+1,right);
		inv_count+=merge(arr,temp,left,mid+1,right);
	}
	return inv_count;
}
int main()
{

 long long int n;
 cin>>n;
 long long int arr[n];
 long long int temp[n];
 for(long long int i=0;i<n;i++)
    cin>>arr[i];
  cout<<count_Inversion(arr,temp,0,n-1)<<"\n";
  return 0;
}
