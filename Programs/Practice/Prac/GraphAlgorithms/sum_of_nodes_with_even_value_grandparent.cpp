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


void dfs(TreeNode *root,int &res)
{
        //if  empty tree
        if(root==NULL)
              return;
        if(root->data%2==0)
        {
            //if left &&left->left
            if(root->left!=NULL&&root->left->left!=NULL)
                  res+=root->left->left->data;
            //if left &&left ->right
            if(root->left!=NULL &&root->left->right!=NULL)
                   res+=root->left->right->data;
            //if right&&right->left
            if(root->right!=NULL &&root->right->left!=NULL)
                   res+=root->right->left->data;
            //if right&&right->right
            if(root->right!=NULL&&root->right->right!=NULL)
                   res+=root->right->right->data;
        }
        //left subtree
        dfs(root->left,res);
        //right subtree
        dfs(root->right,res);
}
int sumEvenGrandparent(TreeNode* root) 
{
       int res=0;
       dfs(root,res);
       return res;
}

int main()
{
    TreeNode *root= new TreeNode(6);
    root->left=new TreeNode(7);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(7);
    cout<<sumEvenGrandparent(root);
    return 0;
}