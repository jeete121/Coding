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

pair<int, bool> countUnivalSubtreesHelper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, bool> p({0, true});
        return p;
    }
    pair<int, bool> left = countUnivalSubtreesHelper(root->left);
    pair<int, bool> right = countUnivalSubtreesHelper(root->right);
    int total_count = left.first + right.first;
    if (left.second && right.second)
    {
        if (root->left != NULL && root->data != root->left->data)
            return {total_count, false};
        if (root->right != NULL && root->data != root->right->data)
            return {total_count, false};
        return {total_count + 1, true};
    }
    return {total_count, false};
}
int countUnivalSubtrees(TreeNode *root)
{
    pair<int, bool> p = countUnivalSubtreesHelper(root);
    return p.first;
}

int main()
{

    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);

    cout << countUnivalSubtrees(root);

    return 0;
}