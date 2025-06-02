#include <bits/stdc++.h>
using namespace std;

/* node for linked list:*/
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* prev = NULL, *nextNode = NULL;
    Node* curr = head;
    while(curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* curr = num1;
        int m =0;
        while(curr!= NULL)
        {
            m++;
            curr = curr->next;
        }
        int n=0;
        curr = num2;
        while(curr!= NULL)
        {
            n++;
            curr = curr->next;
        }
        num1 = reverse(num1);
        num2 = reverse(num2);
        int carry = 0;
        Node* temp = NULL;
        if(m>=n){
            curr = num1;
            temp = num2;
        }
        else{
            curr = num2;
            temp = num1;
        }
        Node* prev = curr;
        while(temp)
        {
            int num = curr->data + temp->data + carry;
            curr->data = num%10;
            carry = num/10;
            prev = curr;
            curr = curr->next;
            temp = temp->next;
        }
        
        while(curr)
        {
            int num = curr->data + carry;
            curr->data = num%10;
            carry = num/10;
            curr = curr->next;
        }
        if(carry){
            prev->next = new Node(carry);
        }
        
        curr = m >= n ? num1: num2;
        Node* head = reverse(curr);

        // Remove leading zeros
        while(head->data == 0 && head->next!= NULL)
        {
            temp= head;
            head = head->next;
            delete temp;
        }
        return head;
    }
};

// Function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
// Function to delete the linked list
void deleteList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}
// Main function to demonstrate the addition of two linked lists
int main() {
    // Creating two linked lists representing numbers
    // List 1: 2 -> 4 -> 3 (represents 342)
    Node* num1 = createNode(2);
    num1->next = createNode(4);
    num1->next->next = createNode(3);

    // List 2: 5 -> 6 -> 4 (represents 465)
    Node* num2 = createNode(5);
    num2->next = createNode(6);
    num2->next->next = createNode(4);

    Solution sol;
    Node* result = sol.addTwoLists(num1, num2);

    cout << "Resultant Linked List: ";
    printList(result); 

    // Clean up memory
    deleteList(num1);
    deleteList(num2);
    deleteList(result);

    return 0;
}
// This code defines a linked list structure and implements a function to add two numbers represented by linked lists.