#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {

    }
    TreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void dfs(TreeNode *&root1,TreeNode *root)
{
        if(root==NULL)
              return;
        dfs(root1,root->left);
        root1->right=new TreeNode(root->data);
        root1=root1->right;
        dfs(root1,root->right);
}
TreeNode* increasingBST(TreeNode* root) 
{
        TreeNode *root1=new TreeNode();
        TreeNode *temp=root1;
        dfs(root1,root);
        return temp->right;
}
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
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(1);
    root->right=new TreeNode(7);
    TreeNode *incres=increasingBST(root);
    inorderTraversal(incres);
    return 0;
}