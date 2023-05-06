#include <bits/stdc++.h>
using namespace std;

//maximum priority queue
priority_queue<double> max1;

//minimum priority queue
priority_queue<double,vector<double>,greater<double>> min1;

//variable to hold the median
double median=0;

//add numner into the priority
//queues
void addNum(int num) 
{

    //if both are of equal size

    if(max1.size()==min1.size())
        {

            //if current element is 
            //greter than median then
            //push into minimum priority
            //queue and set meadin as top
            //of min priority queue
            if(num>median)
            {
                min1.push(num);
                median=min1.top();
            }

           //else push into the max  queue
           //and set median as top of max queue
            else
            {
                max1.push(num);
                median=max1.top();
            }
       }

       //if min size is more
        else if(min1.size()>max1.size())
        {

            //if element is more than median
            //then push the top of min into max
            //and current element into the min
            if(num>median)
            {
                max1.push(min1.top());
                min1.pop();
                min1.push(num);
            }
          //else push into the max
            else
                 max1.push(num);

            //set median as average of
            //min top and max top elements
            median=(min1.top()+max1.top())/2;
            
        }
       //if max size if greater
        else
        {
            //if current is more than then
            //median then push into the min
            //queue
            if(num>median)
            {
                min1.push(num);
            }

            //else push the top of max into
            //the min and current into the max
            else
            {
                min1.push(max1.top());
                max1.pop();
                max1.push(num);
            }
            //set the median as average of
            //top of min and max
            median=(min1.top()+max1.top())/2;
        }
}

//function to find the meadin of running
//stream     
double findMedian() {
        return median;
}
int main()
{
    int arr[]={2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
      {
          addNum(arr[i]);
          cout<<findMedian()<<" ";
      }
    return 0;
}
