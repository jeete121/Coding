#include <bits/stdc++.h>
using namespace std;

//functiom to get the maximum value in the window
int getmax(stack<pair<int, int>> &st1, stack<pair<int, int>> &st2)
{

    //if any stack is empty then return the top
    //elmemt of one which is non empty
    if (st1.empty() || st2.empty())
        return st1.empty() ? st2.top().second : st1.top().second;

    //else return the maximum of both the stacks
    return max(st1.top().second, st2.top().second);
}

//function to add new element
void add(stack<pair<int, int>> &st1, int new_element)
{

    //find the new maximum value if
    //stack is empty then maximum is the current element
    //else the maximum is max of cuurent element and top of stack
    int max1 = st1.empty() ? new_element : max(new_element, st1.top().second);

    //push into the stack with new max
    st1.push({new_element, max1});
}

//function to remove the element
void remove(stack<pair<int, int>> &st1, stack<pair<int, int>> &st2)
{

    //if stack 2 is empty
    if (st2.empty())
    {

        //put all of stack one into stack 2
        //means convert into the queue
        while (!st1.empty())
        {
            int element = st1.top().first;
            st1.pop();
            int max1 = st2.empty() ? element : max(element, st2.top().second);
            st2.push({element, max1});
        }
    }

    //delete the top element from stack 2
    st2.pop();
}

//function to find the maximum in window of
//given size
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    stack<pair<int, int>> st1, st2;

    //add k elements
    for (int i = 0; i < k; i++)
        add(st1, nums[i]);
    vector<int> res;

    //push into the anwer
    res.push_back(getmax(st1, st2));

    //inerate for remaining elements
    for (int i = k; i < nums.size(); i++)
    {

        //remove the start element
        remove(st1, st2);

        //add new elements
        add(st1, nums[i]);

        //push into the result
        res.push_back(getmax(st1, st2));
    }
    return res;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 8, 7};
    int k = 3;
    vector<int> maximum = maxSlidingWindow(arr, k);
    for (int i = 0; i < maximum.size(); i++)
        cout << maximum[i] << " ";
    return 0;
}