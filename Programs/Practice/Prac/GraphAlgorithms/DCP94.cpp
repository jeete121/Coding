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
int sum(TreeNode *root, int &res)
{
    if (root == NULL)
        return 0;

    //call for left subtree
    int left = sum(root->left, res);

    //call for right subtree
    int right = sum(root->right, res);

    int x = max(max(left, right) + root->data, root->data);
    int y = max(x, left + right + root->data);
    res = max(res, y);
    return x;
}
int maxPathSum(TreeNode *root)
{
    int x = INT_MIN;
    int res = sum(root, x);
    return x;
}
int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root);

    return 0;
}