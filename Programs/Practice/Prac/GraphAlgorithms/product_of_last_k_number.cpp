#include <bits/stdc++.h>
using namespace std;

vector<int> v, prod;

void add(int num)
{
    v.push_back(num);
    if (prod.size() == 0)
    {
        if (num > 0)
            prod.push_back(num);
    }
    else
    {
        if (num > 0)
            prod.push_back(prod[prod.size() - 1] * num);
        else
            prod.clear();
    }
}

int getProduct(int k)
{
    if (prod.size() < k)
        return 0;
    if (prod.size() == k)
        return prod[k - 1];
    else
        return prod[prod.size() - 1] / prod[prod.size() - k - 1];
}

int main()
{
    v.clear();
    prod.clear();
    int arr[]={3,0,2,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
       add(arr[i]);
    cout << getProduct(2);
    return 0;
}