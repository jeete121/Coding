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
vector<int> v;
void dfs(TreeNode *root)
{
    if (root == NULL)
        return;
    dfs(root->left);
    v.push_back(root->data);
    dfs(root->right);
}
int minDiffInBST(TreeNode *root)
{
    int minimumDiff = INT_MAX;
    v.clear();
    dfs(root);
    for (int i = 1; i < v.size(); i++)
    {
        minimumDiff = min(minimumDiff, v[i] - v[i - 1]);
    }
    return minimumDiff;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << minDiffInBST(root);

    return 0;
}