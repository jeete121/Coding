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


//function to check for
//leaf node
bool isleaf(TreeNode *root)
{
   //if tree is empty
    if(root==NULL)
        return false;
    
    //if the  node is leaf node
    if(root->left==NULL &&root->right== NULL)
        return true;
   return false;
}

//function to find the sum of left
//leaf nodes
int sumOfLeftLeaves(TreeNode* root) 
{
   int res=0;
    if(root!=NULL)
        {

         //left leaf node
          if(isleaf(root->left))
                  res+=root->left->data;
           else
               res+=sumOfLeftLeaves(root->left);
            res+=sumOfLeftLeaves(root->right);
     }
        return res;
}
int main()
{
  TreeNode *root=new TreeNode(3);
  root->left=new TreeNode(9);
  root->right=new TreeNode(20);
  root->right->left=new TreeNode(15);
  root->right->right=new TreeNode(7);
  int sum=sumOfLeftLeaves(root);
  cout<<sum<<"\n";
  return 0;
}
