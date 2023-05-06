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

int  dfs(TreeNode *root,int &sum)
{
    //base case if tree is empty
    if(root==NULL)
        return 0;

    //call for left subtree
    int leftsum=dfs(root->left,sum);

    //call for right subtree
    int rightsum=dfs(root->right,sum);
    sum+=abs(leftsum-rightsum);
    return leftsum+rightsum+root->data;
}
int findTilt(TreeNode* root)
{
        int sum=0;
        int c=dfs(root,sum);
        return sum;
}

int main()
{
     TreeNode *root=new TreeNode(1);
     root->left=new TreeNode(2);
     root->right=new TreeNode(3);
     cout<<findTilt(root);
     return 0;
}