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
//Function to find postorder Traversal
//of tree
void postorderTraversal(TreeNode *root)
{
    //Base Case
    if(root==NULL)
       return;
   
    //visit left subtree
    postorderTraversal(root->left);
    //visit right subtree
    postorderTraversal(root->right);
     //print root data
    cout<<root->data<<" ";
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Postorder Traversal\n";
    postorderTraversal(tree);
    return 0;
}
//Time Complexity: O(n)
