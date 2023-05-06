#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node(int val) 
     {
      this->val=val;
      this->next=NULL;
      this->right=NULL;
      this->left=NULL;
      }

};

//function to connect nodes at the 
//each level
Node* connect(Node* root) 
{
    queue<Node*> q;
    if(root==NULL)
       return NULL;
    q.push(root);
    while(!q.empty())
     {
         int len=q.size();
         Node *prev=NULL;
         while(len--)
         {
             Node *temp=q.front();
             q.pop();
             if(temp==NULL)
                    continue;
             prev?(prev->next=temp):NULL;
             prev=temp;
             q.push(temp->left);
             q.push(temp->right);
         }
     }
     return root;
}

//function to print the tree
void printTree(Node *root)
{
    queue<Node*>q;
    q.push(root);
    vector<string> vec;
    while(!q.empty())
     {
         int len=q.size();
         while(len--)
         {  
           root=q.front();
           q.pop();
        
           
        if(root!=NULL)
          {
               vec.push_back(to_string(root->val));
              q.push(root->left);
              q.push(root->right);
          }
         }
         vec.push_back("#");
     }
      for(int i=0;i<vec.size()-2;i++)
        cout<<vec[i]<<",";
     cout<<vec[vec.size()-2];
}
int main()
{
  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->right=new Node(7);
  Node *root1=connect(root);
  printTree(root1);
  return 0;
}