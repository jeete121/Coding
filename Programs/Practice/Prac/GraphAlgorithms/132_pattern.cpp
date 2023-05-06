#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int> &arr)
{

    //find the length of array
    int n = arr.size();
    stack<int> s;

    int min1 = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        //if we find the pattern then
        //return true
        if (min1 > arr[i])
        {
            return true;
            
        }
        //update the min1 value
        while (!s.empty() && s.top() < arr[i])
        {
            min1 = s.top();

            //remove from the stack
            s.pop();
        }

        //add into the stack
        s.push(arr[i]);
    }
    return false;
}
int main()
{
    vector<int> nums = {3, 1, 4, 2};
    if (find132pattern(nums))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}