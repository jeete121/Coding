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

//function to find the maximum
//sum of the path
int maxPathSum(TreeNode *root,int &res)
{
    //if tree is empty
    if(root==NULL)
         return 0;
    //call for left subtree
    int left=maxPathSum(root->left,res);

    //call for right subtree
    int right=maxPathSum(root->right,res);

    //update x as max of left right +root data,root data
    int x=max(max(left,right)+root->data,root->data);
    int y=max(x,left+right+root->data);
    res=max(res,y);
    return x;
}

int main()
{
    TreeNode *root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    int x=INT_MIN;
    int maxSum=maxPathSum(root,x);
    cout<<x<<"\n";
}