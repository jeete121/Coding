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
//Function to check for valid
//BST
bool isValidBST(TreeNode *root,long long min1,long long max1)
{
   if(root==NULL)
       return true;
   if(root->data<=min1||root->data>=max1)
       return false;
   return isValidBST(root->left,min1,root->data)
          &&isValidBST(root->right,root->data,max1);
}
bool isValidBST(TreeNode* root) 
{
    return isValidBST(root,LLONG_MIN,LLONG_MAX);
}
int main()
{
    TreeNode *tree=new TreeNode(2);
    tree->left=new TreeNode(1);
    tree->right=new TreeNode(3);
    bool flag=isValidBST(tree);
    if(flag)
       cout<<"Tree is BST\n";
    else
      cout<<"Tree is not BST\n";
    return 0;
}
