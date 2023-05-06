#include <bits/stdc++.h>
using namespace std;
//struct for treenode
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
        if(root==NULL)
        {
           return new TreeNode(val);
        }

        //call for left subtree
        if(root->data>val)
               root->left=insertIntoBST(root->left,val);

        //call for right subtree
        else
             root->right= insertIntoBST(root->right,val);
        return root;
        
}
//function to print the tree
void printTree(TreeNode *root)
{
    queue<TreeNode*>q;
    q.push(root);
    vector<string> vec;
    while(!q.empty())
     {
         root=q.front();
         q.pop();
         if(root==NULL)
         {
             continue;
         }
         else
            vec.push_back(to_string(root->data));
        if(root!=NULL)
          {
              q.push(root->left);
              q.push(root->right);
          }
     }
      for(int i=0;i<vec.size()-1;i++)
        cout<<vec[i]<<",";
    cout<<vec[vec.size()-1];
}
int main()
{
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int val=5;

    TreeNode *tree=insertIntoBST(root,val);
    
    printTree(tree);
    return 0;

}