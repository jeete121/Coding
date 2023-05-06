#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int value;
    Node *next;

    //create a node with the value
    Node(int new_value)
    {
        this->value = new_value;
        this->next = NULL;
    }

    static Node *XOR(Node *pervious, Node *next)
    {
        return (Node *)((uintptr_t)(pervious) ^ (uintptr_t)(next));
    }
};

class XOR_LL
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    XOR_LL(Node *head_node)
    {
        head = head_node;
        tail = head_node;
        length += 1;
    }

    void add(int value)
    {
        Node *new_node = new Node(value);

        new_node->next = Node::XOR(tail, NULL);

        if (tail != NULL)
        {
            Node *next = Node::XOR(tail->next, NULL);
            tail->next = Node::XOR(new_node, next);
        }
        length += 1;
        tail = new_node;
    }

    Node *get(int index)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        for (int i = 0; i < index; i++)
        {
            next = Node::XOR(prev, curr->next);

            prev = curr;
            curr = next;
        }
        return curr;
    }

    void print_list()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        std::cout << "The XOR linked list contains: ";

        while (curr != NULL)
        {
            std::cout << curr->value << " ";

            next = Node::XOR(prev, curr->next);

            prev = curr;
            curr = next;
        }
        std::cout << "\n";
    }
};

int main()
{
    // Create the XOR linked list
    Node *head = new Node(1);
    XOR_LL xor_ll(head);
    xor_ll.add(2);
    xor_ll.add(3);
    xor_ll.add(4);
    xor_ll.add(5);

    // Print the list
    xor_ll.print_list();

    // Get the node at the index
    // Indexing starts at 0
    int index = 2;
    Node *indexed_node = xor_ll.get(index);
    cout << "The value of XORLinklist at index "
         << index << " is " << indexed_node->value << "\n";

    return 0;
}