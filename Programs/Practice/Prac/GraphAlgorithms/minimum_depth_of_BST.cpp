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


int minDepth(TreeNode* root) 
{
        if(root==NULL)
              return 0;
        if(root->left==NULL &&root->right==NULL)
               return 1;
        if(root->left==NULL)
               return 1+minDepth(root->right);
        if(root->right==NULL)
               return 1+minDepth(root->left);
        return min(minDepth(root->left),minDepth(root->right))+1;
}

int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<minDepth(root);
    return 0;
}
