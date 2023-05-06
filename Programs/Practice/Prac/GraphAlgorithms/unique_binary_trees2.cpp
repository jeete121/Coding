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



//function to generate all trees whose
//values lies between start and end
vector<TreeNode*> generateTrees(int start,int end)
{
        vector<TreeNode*> res;

        //base case
        if(start>end)
        {
            res.push_back(NULL);
            return res;
        }

        //itearte from start till end
       for(int i=start;i<=end;i++)
       {

           //generate left subtree
           vector<TreeNode*> left=generateTrees(start,i-1);

           //generate right subtree
           vector<TreeNode*> right=generateTrees(i+1,end);

           //make the tree
           for(int j=0;j<left.size();j++)
           {
               TreeNode *left1=left[j];
               for(int k=0;k<right.size();k++)
               {
                   TreeNode *right1=right[k];
                   TreeNode *node=new TreeNode(i);
                   node->left=left1;
                   node->right=right1;
                   res.push_back(node);
               }
           }
       }
        return res;
}
vector<TreeNode*> generateTrees(int n) 
{
        vector<TreeNode*> res;
        if(n==0)
               return res;
      return generateTrees(1,n);   
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
    int n=3;
    vector<TreeNode*> trees=generateTrees(n);
    cout<<"[";
    for(int i=0;i<trees.size();i++)
       {
           cout<<"[";
           printTree(trees[i]);
           cout<<"]";
           if(i!=trees.size()-1)
             cout<<",";
       }
      cout<<"]";
    return 0;
}