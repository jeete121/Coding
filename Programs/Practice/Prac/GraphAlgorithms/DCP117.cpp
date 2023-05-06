#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int minLevelSum(TreeNode *r)
{
    if (r == NULL)
        return 0;
    int level = 1, sum = r->data;
    int ansLevel = level, ansSum = sum;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty())
    {
        int capacity = q.size();
        level++;
        sum = 0;
        int cnt = 0;
        while (capacity--)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                sum += node->left->data;
                q.push(node->left);
                cnt++;
            }
            if (node->right)
            {
                sum += node->right->data;
                q.push(node->right);
                cnt++;
            }
        }
        if (ansSum > sum && cnt > 0)
        {
            ansSum = sum;
            ansLevel = level;
        }
    }
    return ansLevel;
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-6);

    cout << minLevelSum(root);

    return 0;
}