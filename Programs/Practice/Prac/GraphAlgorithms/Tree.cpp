#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
//Function to find inorder Traversal
//of tree
void inorderTraversal(TreeNode *root)
{
    //Base Case
    if(root==NULL)
       return;
    //visit left subtree
    inorderTraversal(root->left);
    // visit root
    cout<<root->data<<" ";
    //visit right subtree
    inorderTraversal(root->right);
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Inorder Traversal\n";
    inorderTraversal(tree);
    return 0;
}
//Time Complexity: O(n)
