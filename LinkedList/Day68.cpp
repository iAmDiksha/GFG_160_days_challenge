#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to reverse K groups
Node *reverseKGroup(Node *head, int k) {
    if(head == NULL)
    {
        return head;
    }
    Node* curr = head, *newHead = NULL, *tail = NULL;
    while(curr)
    {
        Node* groupHead = curr;
        Node* prev = NULL;
        Node* nextNode = NULL;
        int count =0;
        while(curr != NULL && count <k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nextNode;
            count++;
        }
        if(newHead == NULL)
        {
            newHead = prev;
        }
        if(tail)
        {
            tail->next = prev;
        }
        tail = groupHead;
    }
    return newHead;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    
    // Creating a sample singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseKGroup(head, 3);
    printList(head); 

    return 0;
}