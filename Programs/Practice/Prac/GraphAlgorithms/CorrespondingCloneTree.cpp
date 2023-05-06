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


TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
    TreeNode* target) 
{
       if(original==NULL ||cloned==NULL)
             return NULL;
      if(original==target)
            return cloned;
      TreeNode *left1=getTargetCopy(original->left,cloned->left,target);
      TreeNode *right1=getTargetCopy(original->right,cloned->right,target);
      if(left1!=NULL)
            return left1;
      return right1;
}

int main()
{ 
  TreeNode *root=new TreeNode(1);
  root->left=new TreeNode(2);

  TreeNode *target=root->left;
  root->left->left=new TreeNode(3);
  TreeNode *cloned=root;
  TreeNode *get=getTargetCopy(root,cloned,target);
  cout<<get->data;
  return 0;

}
