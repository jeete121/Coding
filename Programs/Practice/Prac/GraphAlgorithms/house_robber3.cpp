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


int dfs(TreeNode *root)
{
        if(root==NULL)
              return 0;
        int sum=0;
        //call for left subtree
        if(root->left)
              sum+=dfs(root->left);

        //call for right subtree
        if(root->right)
              sum+=dfs(root->right);
        int temp=0;
        if(root->left)
           {
               if(root->left->left)
                     temp+=root->left->left->data;
            if(root->left->right)
                 temp+=root->left->right->data;
           }
        if(root->right)
        {
            if(root->right->left)
                   temp+=root->right->left->data;
            if(root->right->right)
                   temp+=root->right->right->data;
        }
           root->data=max(root->data+temp,sum);
           return root->data;
    }
int rob(TreeNode* root) 
{
        return dfs(root);
}

int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(1);
    cout<<rob(root);
}