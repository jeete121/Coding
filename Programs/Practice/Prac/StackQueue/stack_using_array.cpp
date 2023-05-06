#include <bits/stdc++.h>
using namespace std;

class Stack {
    // initialize the default capacity
     int DEFAULT_CAPACITY = 10;
    // array
    int array[10];
    // initialization of top=-1
    int TOP = -1;

    // constructor with capacity
    public:
    Stack(int maxSize) {
        this->DEFAULT_CAPACITY = maxSize;
         array[DEFAULT_CAPACITY];
        this->TOP = -1;
    }

    // constructor with default capacity
    Stack() {
        array[DEFAULT_CAPACITY];
        this->TOP = -1;
    }

    // add value in stack
    void push(int number) {
        // if not full, then add else Overflow
        if (!isFull()) {
            TOP++;
            array[TOP] = number;
        } else {
            cout<<"Overflow!! ";
        }
    }

// get top and top remove element from stack
    void pop() {
        if (!this->isEmpty())
            array[TOP--];
        else {
            cout<<"Underflow!! ";
        }
    }

    // only get top element from stack
    int peek() {
        if (!this->isEmpty())
            return array[TOP];
        else {
            cout<<"Underflow!! ";
            return INT_MIN;
        }
    }

     int size() {
        return TOP + 1;
    }

    bool isEmpty() {
        return TOP == -1;
    }

    bool isFull() {
        return TOP == DEFAULT_CAPACITY - 1;
    }

};
int main()
{
    // create stack with size
    Stack s(3);
    // push 1 element
    cout<<"Push(1): ";
    s.push(1); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
   // pop element
    cout<<"Peek(): "<<s.peek();
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Pop() : ";
    s.pop();
    cout<<": Size() : "<<s.size()<<"\n";
    // pop element
    cout<<" Peek(): "<<s.peek(); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Pop() : ";
    s.pop();
    cout<<": Size() : "<<s.size()<<"\n";
    // push another element
    cout<<" Push(1): ";
    s.push(1); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
    // push another element
    cout<<"Push(2): ";
    s.push(2);
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
   cout<<": Size() : "<<s.size()<<"\n";
   // push another element
    cout<<"Push(3): ";
    s.push(3); 
   cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
        // push another element
    cout<<" Push(4): ";
    s.push(4); 
    cout<<": isEmpty(): "<<s.isEmpty();
    cout<<": Peek() : "<<s.peek();
    cout<<": Size() : "<<s.size()<<"\n";
    return 0;
}
