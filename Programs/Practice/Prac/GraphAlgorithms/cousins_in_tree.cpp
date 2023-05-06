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



int height(TreeNode *root,int x,int &parent,int level)
{
    if(root==NULL)
         return 0;
    if(root->data==x)
        return level;
    parent=root->data;
    int h1=height(root->left,x,parent,level+1);
    if(h1!=0)
      return h1;
    parent=root->data;
    return height(root->right,x,parent,level+1);
}
bool isCousins(TreeNode* root, int x, int y) 
{
        int parentx=-1;
        int parenty=-1;
        if(root->data==x || root->data==y)
            return false;
        int h1=height(root,x,parentx,0);
        int h2=height(root,y,parenty,0);
        if(h1==h2&&parentx!=parenty)
            return true;
        return false;
        
}

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    int x=4,y=3;
    if(isCousins(root,x,y))
      cout<<"true";
    else
      cout<<"false";

    return 0;
}