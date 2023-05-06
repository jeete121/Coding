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
int sum = 0;
TreeNode *bstToGst(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    //call for right subtree
    bstToGst(root->right);

    //add current node into sum
    sum += root->data;

    //uodate root data
    root->data = sum;

    //call for left subtree
    bstToGst(root->left);
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
            vec.push_back("null");
         else
            vec.push_back(to_string(root->data));
        if(root!=NULL)
          {
              q.push(root->left);
              q.push(root->right);
          }
     }
     int j=vec.size()-1;
     while(j>0&&vec[j]=="null")
        j--;
      vec.resize(j);
      for(int i=0;i<j;i++)
        cout<<vec[i]<<",";
      cout<<vec[j];
}
int main()
{
    //[3,2,4,1]
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(2);
    root->right=new TreeNode(4);
    root->left->left=new TreeNode(1);

    root=bstToGst(root);

    printTree(root);

}