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
//Function to find preorder Traversal
//of tree
void preorderTraversal(TreeNode *root)
{
    //Base Case
    if(root==NULL)
       return;
    //print root data
    cout<<root->data<<" ";
    //visit left subtree
    preorderTraversal(root->left);
    //visit right subtree
    preorderTraversal(root->right);
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Preorder Traversal\n";
    preorderTraversal(tree);
    return 0;
}
//Time Complexity: O(n)
