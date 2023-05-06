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
bool isValid(TreeNode *root, long long min1, long long max1)
{
    if (root == NULL)
        return true;
    if (root->data <= min1 || root->data >= max1)
        return false;
    return isValid(root->left, min1, root->data) &&
           isValid(root->right, root->data, max1);
}
bool isValidBST(TreeNode *root)
{
    return isValid(root, LLONG_MIN, LLONG_MAX);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root))
        cout << "true";
    else
        cout << "false";
    return 0;
}