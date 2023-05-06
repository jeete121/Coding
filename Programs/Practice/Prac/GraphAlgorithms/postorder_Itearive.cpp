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
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    if(root==NULL)
       return res;
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty())
      {
            TreeNode *temp=st.top();
            res.push_back(temp->data);
            st.pop();
            if(temp->left)
                 st.push(temp->left);
             if(temp->right)
                 st.push(temp->right);
          
      }
      reverse(res.begin(),res.end());
     return res;
}
int main()
{
    TreeNode *tree=new TreeNode(1);
    tree->right=new TreeNode(2);
    tree->right->left=new TreeNode(3);
    cout<<"Postorder Traversal\n";
    vector<int> res=postorderTraversal(tree);
    int n=res.size();
    for(int i=0;i<n;i++)
       cout<<res[i]<<" ";
    
    return 0;
}
//Time Complexity: O(n)
