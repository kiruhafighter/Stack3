// Stack3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct StackNode {
    Node* top;
    StackNode() { top = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = top;
        Node* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        top = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    StackNode ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given stack \n";
    ll.print();

    ll.reverse();

    cout << "\nReversed stack \n";
    ll.print();
    return 0;
}
