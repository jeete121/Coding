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

//find minimum value node in a given BST
TreeNode *findMinimum(TreeNode *root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root;
}

void inorderSuccessor(TreeNode *root, TreeNode *&succ, int key)
{
    // base case
    if (root == NULL)
    {
        succ = NULL;
        return;
    }
    if (root->data == key)
    {
        if (root->right)
        {
            succ = findMinimum(root->right);
        }
    }

    else if (key < root->data)
    {
        // update successor to the current node
        // and reccur for left subtree
        succ = root;
        inorderSuccessor(root->left, succ, key);
    }

    // if the given key is more than the root node,
    // then reccur for the right subtree
    else
    {
        inorderSuccessor(root->right, succ, key);
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(22);
    TreeNode *succ = NULL;
    root->right->right = new TreeNode(35);

    int key = 22;

    inorderSuccessor(root, succ, key);

    cout << succ->data;

    return 0;
}