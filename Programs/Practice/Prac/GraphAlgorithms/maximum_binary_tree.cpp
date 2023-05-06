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

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
        TreeNode *root=NULL;
        if(nums.size()==0)
              return root;
        int max1=INT_MIN,j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max1)
            {
                max1=nums[i];
                j=i;
            }
        }
        root=new TreeNode(nums[j]);
        vector<int> left1,right1;
        for(int i=0;i<j;i++)
              left1.push_back(nums[i]);
        
        for(int i=j+1;i<nums.size();i++)
              right1.push_back(nums[i]);

        //call for left subtree
        root->left=constructMaximumBinaryTree(left1);

        //call for right subtree
        root->right=constructMaximumBinaryTree(right1);
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
    vector<int> nums ={3,2,1,6,0,5};
    TreeNode *root=constructMaximumBinaryTree(nums);

    printTree(root);
    return 0;

}