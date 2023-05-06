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

int dfs(TreeNode *root,int max1)
{
        if(root==NULL)
              return 0;
        int cnt=0;
        if(root->data>=max1)
        {
            max1=root->data;
            cnt++;
        }
        int leftAns=dfs(root->left,max1);
        int rightAns=dfs(root->right,max1);
        return leftAns+rightAns+cnt;
}
int goodNodes(TreeNode* root) 
{
      if(root==NULL)
            return 0;
      return dfs(root,INT_MIN);
}


int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(2);
    cout<<goodNodes(root);
    return 0; 
}