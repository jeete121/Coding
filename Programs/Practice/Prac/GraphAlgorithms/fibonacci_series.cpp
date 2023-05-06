#include <bits/stdc++.h>
using namespace std;
//Function to find fibonacci
//series
vector<int> fibonacciSeries(int num)
{
    vector<int> fibo;
    fibo.push_back(0);
    if(num==1)
       return fibo;
    fibo.push_back(1);
    int a=0,b=1;
    int temp;
    for(int i=2;i<num;i++)
        {
            temp=a+b;
            fibo.push_back(temp);
            a=b;
            b=temp;
        }
    return fibo;
}
int main()
{
    int num=10;
    vector<int> fiboSeries=fibonacciSeries(num);
    cout<<"Fibonacci Series is ";
    for(int i=0;i<fiboSeries.size();i++)
       cout<<fiboSeries[i]<<" ";
    return 0;
}
//Time Complexity: O(n)
