#include <bits/stdc++.h>
using namespace std;

//function to sort the array
//in ascending order
void sortingAsc(int arr[], int N)
{
    for (int i = 0; i < N; i++)
     {
       int min = i;
        for (int j = i + 1; j < N; j++) {
             // ascending order
                if (arr[min] >arr[j]) {
                    min = j;
                }
            }
            // Swapping element
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
}
int main()
{
      int arr[] = { 3, 1, 4, 12, 6, 9,2 };
      int n=sizeof(arr)/sizeof(arr[0]);

     sortingAsc(arr, n);

     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
