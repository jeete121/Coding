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


TreeNode *sortedArrayToBST(vector<int> &v,int start,int end)
{
        if(start>end)
              return NULL;
        int mid=start+(end-start)/2;
        TreeNode *root=new TreeNode(v[mid]);
        root->left=sortedArrayToBST(v,start,mid-1);
        root->right=sortedArrayToBST(v,mid+1,end);
        return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums)
{
        
        TreeNode *root=sortedArrayToBST(nums,0,nums.size()-1);
        return root;
}
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
  vector<int> arr={-10,-3,0,5,9};
  TreeNode *root=sortedArrayToBST(arr);
  cout<<"[";
  printTree(root);
  cout<<"]";
  return 0;
}
