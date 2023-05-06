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

//function to find the lowest common
//ancestor of the binary search tree
TreeNode* lowestCommonAncestor(TreeNode* root, 
             TreeNode* p, TreeNode* q) 
{
       //base case if root is NULL
        if(root==NULL)
              return NULL;

        //base case
        if(p->data>=root->data&&q->data<=root->data)
                return root;
        
        //base case
        if(p->data<=root->data&&q->data>=root->data)
               return root;
        else
        {

            //call for left subtree
            if(p->data<root->data &&q->data<root->data)
             return lowestCommonAncestor(root->left,p,q);

             //call for right subtree
            else
                return lowestCommonAncestor(root->right,p,q);
        }
}
int main()
{
    TreeNode *tree=new TreeNode(6);
    tree->left=new TreeNode(2);
    TreeNode *p=tree->left;
    tree->right=new TreeNode(8);
    TreeNode *q=tree->right;
    tree->left->left=new TreeNode(0);
    tree->left->right=new TreeNode(4);
    tree->right->left=new TreeNode(7);
    tree->right->right=new TreeNode(9);
    tree->left->right->left=new TreeNode(3);
    tree->left->right->right=new TreeNode(5);
    TreeNode *LCA=lowestCommonAncestor(tree,p,q);
    cout<<LCA->data<<"\n";
    
    return 0;
}