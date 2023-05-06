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
int countVal = 0;

void dfs(TreeNode *root, int path)
{

    //if root is NULL then
    //return
    //base case to terminate the recursion
    if (root == NULL)
        return;
    path = path ^ (1 << root->data);

    //if leaf node
    if (root->left == NULL && root->right == NULL)
    {

        countVal += (path & (path - 1)) == 0 ? 1 : 0;
        return;
    }

    //call for left subtree
    dfs(root->left, path);

    //call for right subtree
    dfs(root->right, path);
}
int pseudoPalindromicPaths(TreeNode *root)
{
    dfs(root, 0);
    return countVal;
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    cout << pseudoPalindromicPaths(root);

    return 0;
}