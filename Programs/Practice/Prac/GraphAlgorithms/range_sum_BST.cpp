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

//function to find the range sum of
//the BST
int rangeSumBST(TreeNode* root, int low, int high) 
{
  //if tree is empty
  //return 0
   if(root==NULL)
         return 0;
   //if root data lies in the given range 
   if(root->data<=high&&root->data>=low)
        return root->data+rangeSumBST(root->left,low,high)
               +rangeSumBST(root->right,low,high);
  //if root data is less than low then 
  //call for right subtree
  else if(root->data<low)
         return rangeSumBST(root->right,low,high);

   //else call for left subtree
    else 
          return rangeSumBST(root->left,low,high);

}
int main()
{
  TreeNode *root=new TreeNode(10);
  root->left=new TreeNode(5);
  root->right=new TreeNode(15);
  root->left->left=new TreeNode(3);
  root->left->right=new TreeNode(7);
  root->right->right=new TreeNode(18);
  int low=7,high=15;
  cout<<rangeSumBST(root,low,high)<<"\n";
  return 0;
}
