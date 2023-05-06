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

int ans = 0;
int toDecimal(vector<int> s)
{
    int decimal = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 1)
            decimal += pow(2, n - i - 1);
    }
    return decimal;
}
void dfs(TreeNode *root, string str, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ans += toDecimal(path);
    }

    dfs(root->left, str, path);
    dfs(root->right, str, path);
}
int sumRootToLeaf(TreeNode *root)
{
    string str = "";
    vector<int> path;
    dfs(root, str, path);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    cout << sumRootToLeaf(root);
    return 0;
}