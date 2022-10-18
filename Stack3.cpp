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
    int size;
    StackNode() { top = NULL; size = 0; }

    //reverse
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

    //print
    void print()
    {
        struct Node* temp = top;
        while (temp != NULL) {
            cout <<" " << temp->data << " "<<endl;
            cout << " " << "||" << " " << endl;
            temp = temp->next;
        }
    }
    // add element
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }
    //delete element
    void pop() 
    {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    //method for clear
    void clear() {
        while (size) {
            pop();
        }
    }
    //method for search element
    bool search(int sdata) {
        Node* temp = top;
        while (temp != NULL) {
            if (temp->data == sdata) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    //method for swap
    void swap() {
        Node* current = top;
        Node* temp = NULL;
        Node* index = NULL;
        if (top == NULL) {
            return;
        }
        else {
            while (current->next != NULL) {
                index = current;
                current = current->next;
            }
            if (top == current) {
                return;
            }
            else if (top->next == current) {
                temp = top;
                top = current;
                top->next = temp;
                temp->next = NULL;
            }
            else {
                temp = top;
                top = current;
                top->next = temp->next;
                index->next = temp;
                temp->next = NULL;
            }
        }
        
        

    }
};

// menu
int menu() {
    cout << "Choose action for Stack from list :" << endl;
    cout << "1. Push to Stack " << endl;
    cout << "2. Pop from Stack " << endl;
    cout << "3. Clear all Stack " << endl;
    cout << "4. Swap first and last elements in Stack " << endl;
    cout << "5. Reverse Stack " << endl;
    cout << "6. Does element belongs to Stack " << endl;
    cout << "7. Print Stack " << endl;
    int result;
    cin >> result;
    return result;
}


int main()
{

    StackNode ll;
    ll.push(5);
    ll.push(4);
    ll.push(3);
    ll.push(2);
    ll.push(1);

    while (true) 
    {
        switch (menu())
        {
        case 1:
            {
                system("cls");
                int case1;
                cout << "Add element: ";
                cin >> case1;
                ll.push(case1);
                cout << "Element pushed" << endl;
            }
        break;
        case 2:
            {
                system("cls");
                ll.pop(); 
                cout << "Element poped" << endl;
            }
        break;
        case 3:
            {
                system("cls");
                ll.clear();
                cout << "Stack cleared" << endl;
            }
        break;
        case 4:
            {
                system("cls");
                ll.swap();
                cout << "Elements swapped" << endl;
            }
        break;
        case 5:
            {
                system("cls");
                ll.reverse();
                cout << "Stack reversed upside down " << endl;

            }
        break;
        case 6:
            {
                system("cls");
                cout << "Enter element to find out if it belongs to Stack " << endl;
                int case6;
                cin >> case6;
                bool find_elem = ll.search(case6);
                if (find_elem) {
                    cout <<"Element " << case6 << " is in the Stack" << endl;
                }
                else {
                    cout << "This element does not belong to Stack" << endl;
                }
            }
        break;
        case 7:
            {
                system("cls");
                ll.print();
            }
            break;
        }
        
        
    
    }
    
    


    return 0;
}
