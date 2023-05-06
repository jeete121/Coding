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

vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
              return res;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
           
            int max1=INT_MIN;
            while(n--)
             {
               
           root=q.front();
                q.pop();
            if(root->data>max1)
                  max1=root->data;
               if(root->left)
                     q.push(root->left);
               if(root->right)
                      q.push(root->right);
             }
            res.push_back(max1);
        }
        return res;
}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(9);
    vector<int> arr=largestValues(root);
    for(int i=0;i<arr.size();i++)
       cout<<arr[i]<<" ";
    return 0;
}