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

//function to find all
//the leaf nodes in binary tree
void allLeafNodes(TreeNode *root,vector<int> &leaf)
{
    //if root is null then return
    if(root==NULL)
       return;

    //if the node is leaf node add
    //into the leaf list
    if(root->left==NULL&&root->right==NULL)
        leaf.push_back(root->data);
    //call for left
    allLeafNodes(root->left,leaf);
    //call for right
    allLeafNodes(root->right,leaf);
}
int main()
{

    TreeNode *tree=new TreeNode(1);
    tree->left=new TreeNode(2);
    tree->right=new TreeNode(3);
    tree->right->left=new TreeNode(4);
    vector<int> leaf;
    allLeafNodes(tree,leaf);
    cout<<"All leaf nodes ";
    for(int i=0;i<leaf.size();i++)
       cout<<leaf[i]<<" ";
    return 0;
}
