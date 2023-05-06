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

//function to count tree nodes
int countNodes(TreeNode *root)
{

    //if tree is empty
    if (root == NULL)
        return 0;

    //if leaf node
    else if (root->left == NULL && root->right == NULL)
        return 1;

    //call for left subtree and right subtree
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << countNodes(root);

    return 0;
}