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
ListNode* removeElement(ListNode *head, int n) 
 {
        // If list is null
        if (head == NULL) {
            return head;
        }

        ListNode *root = head;
        // if deleted element in beginning
        while (root != NULL) {
            // if found then delete
            if (root->val == n) {
                root = root->next;
            } else {
                break;
            }
        }
        ListNode *prev = root;
        ListNode *prev1 = root;
        while (prev !=NULL) {
            // if found nth then delete
            while (prev !=NULL && prev->val == n) {
                prev1->next = prev->next;
                prev = prev->next;
            }
            // change previous
            prev1 = prev;
            if (prev !=NULL)
                prev = prev->next;
        }
        return root;
}
int main()
{
    ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);
        int val = 6;
        ListNode *node = removeElement(head, val);
        cout<<"After Removing :\n";
        linkedListTraversal(node);
}
// Time Complexity : O(n)
// Space Complexity : O(1)