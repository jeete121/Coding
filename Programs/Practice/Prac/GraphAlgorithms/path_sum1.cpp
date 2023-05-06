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


//function to check if their is
//a path from root to leaf with
//given sum
bool hasPathSum(TreeNode* root, int sum)
{
        if(root==NULL &&sum>=0)
               return false;
        else
        {
         bool ans=false;
        int subsum=sum-root->data;
        if(subsum==0&&root->left==NULL&&root->right==NULL)
               return true;
        if(root->left)
               ans=ans||hasPathSum(root->left,subsum);
        if(root->right)
                ans=ans||hasPathSum(root->right,subsum);
        return ans;
        }
}
int main()
{
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    int sum=20;
    if(hasPathSum(root,sum))
      cout<<"true";
    else
     cout<<"false";
     return 0;
    
}