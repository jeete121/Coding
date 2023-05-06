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

int sum(TreeNode *root,int res)
{

      //if tree is empty
        if(root==NULL)
               return 0;

        //update the value
        res=(res*10+root->data);

        //if leaf node then return the resulted sum
        if(root->left==NULL&&root->right==NULL)
               return res;

         //else call for lefr and right subtree
        return sum(root->left,res)+sum(root->right,res);
}

int sumNumbers(TreeNode* root) 
{
        int res=0;
        res=sum(root,0);
        return res;
}

int main()
{
   TreeNode *root=new TreeNode(1);
   root->left=new TreeNode(2);
   root->right=new TreeNode(3);
   cout<<sumNumbers(root);
   return 0;
}