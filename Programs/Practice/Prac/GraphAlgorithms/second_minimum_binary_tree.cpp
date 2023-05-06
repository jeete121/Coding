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

bool flag = false;
void dfs(TreeNode *root, int min1, int &secMin)
{
    if (!root)
        return;
    if (root->data > min1 && root->data <= secMin)
    {
        secMin = root->data;
        flag = true;
    }
    dfs(root->left, min1, secMin);
    dfs(root->right, min1, secMin);
}
int findSecondMinimumValue(TreeNode *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL && root->right == NULL)
        return -1;
    int secMin = INT_MAX;
    flag = false;
    dfs(root, root->data, secMin);
    if (flag == true)
        return secMin;
    else
        return -1;
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << findSecondMinimumValue(root);

    return 0;
}