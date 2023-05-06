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


bool isMirror(TreeNode *root1,TreeNode *root2)
{
        if(root1==NULL && root2==NULL)
               return true;
        if(root1!=NULL &&root2!=NULL && root1->data==root2->data)
               return isMirror(root1->left,root2->right)&&
                    isMirror(root1->right,root2->left);
        return false;
}
bool isSymmetric(TreeNode* root) 
{
        return isMirror(root,root);
}

int main()
{

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    if(isSymmetric(root))
      cout<<"true";
    else
      cout<<"false";
    
     return 0;
    
}
