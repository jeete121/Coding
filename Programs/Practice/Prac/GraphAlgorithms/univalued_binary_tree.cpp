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

//function to check if the tree
//have all value unique or not
bool isSame(TreeNode *root,int val)
{
    //base case empty tree
    if(root==NULL)
              return true;

    //if value is not same then
    //return false
    if(root->data!=val)
        return false;

    //call for both left subtree and right subtree
    return isSame(root->left,val)&&isSame(root->right,val);
        
}
bool isUnivalTree(TreeNode* root) 
{
    if(root==NULL)
        return true;
    return isSame(root,root->data);
}
int main()
{
  TreeNode *root=new TreeNode(1);
  root->left=new TreeNode(1);
  root->right=new TreeNode(1);
  if(isUnivalTree(root))
    cout<<"true";
  else
    cout<<"false";

  return 0;
  
}