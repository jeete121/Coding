#include <bits/stdc++.h>
using namespace std;

//structute of the node
struct Node
{
    Node *left;
    Node *right;
};

//function to add the new data
void insert(int x, Node *head)
{
    Node *curr = head;
    for (int i = 30; i >= 0; i--)
    {
        int val = (x >> i) & 1;

        //if zero then go to left side
        if (val == 0)
        {

            //if left is null then 
            //create a new node for left 
            if (curr->left == NULL)
                curr->left = new Node();

            //move to next of left
            curr = curr->left;
        }

        //if value is 1 then go right side
        else
        {

            //if right is null then create
            //a new node for right
            if (curr->right == NULL)
                curr->right = new Node();

            //move next to right
            curr = curr->right;
        }
    }
}

//function to find the maximum
//value of xor of two numbers in the
//array
int getMax(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    Node *head = new Node();

    //add all value into the sructure
    for (int i = 0; i < n; i++)
        insert(nums[i], head);
    for (int i = 0; i < n; i++)
    {
        long long int curr_xor = 0;
        long long int m = pow(2, 30);
        Node *curr = head;
        for (long long int j = 30; j >= 0; j--)
        {
            long long int val = (nums[i] >> j) & 1;

            //if 0 
            if (val == 0)
            {

                //if right exist
                if (curr->right)
                {
                    curr_xor += m;
                    curr = curr->right;
                }

                //else go for left
                else
                    curr = curr->left;
            }
            //if 1 
            else
            {

                //if left exist
                if (curr->left)
                {
                    curr_xor += m;
                    curr = curr->left;
                }

                //else go for right
                else
                    curr = curr->right;
            }
            m = m / 2;
        }
        //uodate answer
        if (curr_xor > ans)
            ans = curr_xor;
    }
    return ans;
}
int findMaximumXOR(vector<int> &nums)
{
    return getMax(nums);
}

int main()
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums);
    return 0;
}