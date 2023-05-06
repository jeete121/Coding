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


//function to find the sum of deepest leaf nodes
//in the binary tree
int deepestLeavesSum(TreeNode* root) 
{
      //if tree is empty
        if(root==NULL)
               return 0;
       //queue to hold the incoming
       //nodes
       queue<TreeNode*> q;
       q.push(root);
       vector<int> v;

       //iterate till the queue is non
       //empty
      while(!q.empty())
        {

             //find the size of queue
            int len=q.size();
            v.clear();
            //iterate till the length of queue
            while(len--)
            {
                root=q.front();
                q.pop();
                v.push_back(root->data);

                //store the left if exist
                if(root->left)
                      q.push(root->left);

                //store the right if exist
                if(root->right)
                      q.push(root->right);
            }
        }
        int sum=0;

        //find the sum of deepest leaf nodes
        for(int i=0;i<v.size();i++)
               sum+=v[i];
        return sum;

}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(6);
    root->right->right->right=new TreeNode(8);
    root->left->left->left=new TreeNode(7);
    int sum=deepestLeavesSum(root);
    cout<<sum<<"\n";
    return 0;
}