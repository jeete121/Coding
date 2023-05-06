#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {

    }
    TreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//function to seach the
//value in tree and return
//the subtree in which it exist
TreeNode *searchBST(TreeNode* root, int val) 
{
       //if tree is empty
        if(root==NULL)
              return NULL;
        //if root data is same as target value
        if(root->data==val)
              return root;
        //it root data is greater than
        //target value then call for left subtree
        if(root->data>val)
              return searchBST(root->left,val);

        //else call for right subtree
        return searchBST(root->right,val);
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
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int val=2;
    TreeNode *find=searchBST(root,val);
    inorderTraversal(find);
    return 0;

}