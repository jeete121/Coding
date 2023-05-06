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

//function to find the height of tree
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    //left height
    int l = height(root->left);

    //right height
    int h = height(root->right);

    //if left height is greater than right height
    if (l > h)
        return 1 + l;

    //if right height is greater than left height
    else
        return h + 1;
}

//function to find the diameter of binary tree
int diameterOfBinaryTree(TreeNode *root)
{

    //base case
    if (root == NULL)
        return 0;
    int max1 = 0;

    //left height
    int h_left = height(root->left);

    //right height
    int h_right = height(root->right);

    //update maximum diameter
    if (max1 < h_left + h_right)
        max1 = h_left + h_right;

    //call for left subtree
    int l_d = diameterOfBinaryTree(root->left);

    //call for right subtree
    int r_d = diameterOfBinaryTree(root->right);

    //if left diamter is greater than right diameter
    if (l_d > r_d)
        max1 = max(l_d, max1);

    //if right diameter  is greater than left diameter
    else
        max1 = max(max1, r_d);
    return max1;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root);

    return 0;
}