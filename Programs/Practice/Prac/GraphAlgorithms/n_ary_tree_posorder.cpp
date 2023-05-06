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

//function for postorder traversal
vector<int> postOrder(Node* root) 
{
   stack<Node *> st;
   vector<int> res;
   if(root==NULL)
        return res;
   st.push(root);
   Node *curr=NULL;
    while(!st.empty())
    {
        curr=st.top();
        res.push_back(curr->val);
        st.pop();
        for(auto it=curr->children.begin();it!=curr->children.end();it++)
                st.push(*it);
    }
    reverse(res.begin(),res.end());
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

        vector<int> result=postOrder(node);
       for(int i=0;i<result.size();i++)
          cout<<result[i]<<" ";
       return 0;
        
}
