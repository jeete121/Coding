#include <bits/stdc++.h>
using namespace std;
struct  Node
{
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) 
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    }
};

//function to find level order
//traversal of n ary tree
vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL)
              return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
           int len=q.size();
            vector<int> x;
          for(int i=0;i<len;i++)
          {
              Node *temp=q.front();
              q.pop();
              x.push_back(temp->val);
                  for(auto child:temp->children)
                         q.push(child);
          }
            res.push_back(x);
        }
        return res;
}
int main()
{
        // 3 node child
        vector<Node*> node3Child;
        node3Child.push_back(new Node(5));
        node3Child.push_back(new Node(6));

        // 1 node child
        vector<Node*> node1Child;
        node1Child.push_back(new Node(3, node3Child));
        node1Child.push_back(new Node(2));
        node1Child.push_back(new Node(4));

        // root node
        Node *node = new Node(1, node1Child);

        vector<vector<int>> result=levelOrder(node);
        cout<<"[";
       for(int i=0;i<result.size();i++)
          {
              cout<<"[";
              for(int j=0;j<result[i].size();j++)
                 {
                    if(j!=result[i].size()-1)
                       cout<<result[i][j]<<",";
                    else
                    cout<<result[i][j];
                    
                 }
              cout<<"]";
              if(i!=result.size()-1)
                 cout<<", ";
          }
        cout<<"]";
       return 0;
        
}
