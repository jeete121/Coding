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


int dfs(TreeNode *root,int sum)
{

    //if tree is empty
     if(root==NULL)
               return 0;
      //call for left and right
     return (root->data==sum)+dfs(root->left,sum-root->data)
              +dfs(root->right,sum-root->data);
}

//function to count number of
//path with the given sum
int pathSum(TreeNode* root, int sum) 
{
    if(root==NULL)
         return 0;
     return dfs(root,sum)+pathSum(root->left,sum)
         +pathSum(root->right,sum);
}

int main()
{

   TreeNode *root=new TreeNode(10);
   root->left=new TreeNode(5);
   root->right=new TreeNode(-3);
   root->left->left=new TreeNode(3);
   root->left->right=new TreeNode(2);
   root->right->right=new TreeNode(11);
   int sum=8;
   cout<<pathSum(root,sum);
   return 0;
}