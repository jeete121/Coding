#include <bits/stdc++.h>
using namespace std;
struct ListNode
{ 
   int val;
   ListNode *next;
   ListNode(int data)
    {
        this->val=data;
        this->next=NULL;
    }
};
void linkedListTraversal(ListNode *node)
{
        while (node != NULL) {
            cout<<node->val<<" ";
            node = node->next;
        }
}
ListNode* removeDuplicateElement(ListNode *head) 
{
    // If list is null
    if (head==NULL) {
        return head;
        }

    ListNode *root = head;
    ListNode *prev = root;
    int cnt = 0;
    // Iterate till end of list
    while (root != NULL) 
    {
        prev = root;
        root = root->next;
        cnt = 1;
            // Iterate till end of list and duplicate
          while (root != NULL&& prev->val == root->val) {
                cnt++;
                root = root->next;
            }
            if (cnt > 1) {
                prev->next = root;
                prev = root;
            }
       }
   return head;
}
int main()
{
        ListNode *head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(2);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(5);
        head = removeDuplicateElement(head);
        cout<<"After Removing :\n";
        linkedListTraversal(head);
}