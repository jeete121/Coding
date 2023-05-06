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
void dfs(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;

    //call for left subtree
    dfs(root->left, res);

    //root data
    res.push_back(root->data);

    //call for right subtree
    dfs(root->right, res);
}

//function to find the kth smallest element in the
//tree
int kthSmallest(TreeNode *root, int k)
{
    vector<int> res;
    dfs(root, res);
    return res[k - 1];
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;
    cout << kthSmallest(root, k);
}