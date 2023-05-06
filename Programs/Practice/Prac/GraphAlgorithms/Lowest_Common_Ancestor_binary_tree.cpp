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


//funtion to find the Lowest
//common ancestor of binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, 
          TreeNode* p, TreeNode* q) 
{
    //base case
    if(root==NULL)
       return NULL;

    //base case root data is same as 
    //any one of p and then return root
    if(root->data==p->data||root->data==q->data)
         return root;

    //find left LCA
    TreeNode *leftLCA=lowestCommonAncestor(root->left,p,q);

    //find right LCA
    TreeNode *rightLCA=lowestCommonAncestor(root->right,p,q);

    //if both are not NULL then return the root
    if(leftLCA!=NULL&&rightLCA!=NULL)
          return root;
    
    //if left is NULL return right
    if(leftLCA==NULL)
        return rightLCA;
   //else return the left
    return leftLCA;
 }

int main()
{
    TreeNode *tree=new TreeNode(3);
    tree->left=new TreeNode(5);
    TreeNode *p=tree->left;
    tree->right=new TreeNode(1);
    TreeNode *q=tree->right;
    tree->left->left=new TreeNode(6);
    tree->left->right=new TreeNode(2);
    tree->right->left=new TreeNode(0);
    tree->right->right=new TreeNode(8);
    tree->left->right->left=new TreeNode(7);
    tree->left->right->right=new TreeNode(4);
    TreeNode *LCA=lowestCommonAncestor(tree,p,q);
    cout<<LCA->data<<"\n";
    
    return 0;
}