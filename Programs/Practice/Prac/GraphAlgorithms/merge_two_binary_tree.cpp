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

//function to merge two trees
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
    //if first is empty 
    //return second tree  
    if(t1==NULL)
              return t2;
    //if second is empty return first
     if(t2==NULL)
               return t1;

    //store the sum of both the trees 
    t1->data+=t2->data;
    //call for left subtrees
    t1->left=mergeTrees(t1->left,t2->left);

    //call for right subtrees
    t1->right=mergeTrees(t1->right,t2->right);

    //return the merge tree
    return t1;
}
//Function to find inorder Traversal
//of tree
void inorderTraversal(TreeNode *root)
{
    //Base Case
    if(root==NULL)
       return;
    //visit left subtree
    inorderTraversal(root->left);
    // visit root
    cout<<root->data<<" ";
    //visit right subtree
    inorderTraversal(root->right);
}
int main()
{
   //first tree
   TreeNode *t1=new TreeNode(1);
   t1->left=new TreeNode(3);
   t1->right=new TreeNode(2);
   t1->left->left=new TreeNode(5);

   //second tree
   TreeNode *t2=new TreeNode(2);
   t2->left=new TreeNode(1);
   t2->right=new TreeNode(3);
   t2->left->right=new TreeNode(4);
   t2->right->right=new TreeNode(7);

   TreeNode *merge=mergeTrees(t1,t2);
   
   cout<<"Inorder of merge Tree: ";
   inorderTraversal(merge);
   return 0;

}
