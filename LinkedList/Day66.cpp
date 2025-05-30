#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
      Node* rotate(Node* head, int k) {
          if(head == NULL || head->next == NULL) return head;
          Node* temp =head;
          int size = 1;
          while(temp->next != NULL)
          {
              size++;
              temp = temp->next;
          }
          k = k%size;
          Node* new_head = head;
          
          while(k--)
          {
              temp->next = head;
              new_head = head->next;
              head->next = NULL;
              temp = head;
              head = new_head;
          }
          return head;
      }
  };

// Function to create a new node with given data
Node* newNode(int data) {
    Node* new_node = new Node(data);
    return new_node;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code to test the above functions
int main() {
    // Create a linked list 1->2->3->4->5
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    cout << "Original List: ";
    printList(head);

    int k = 2; // Rotate by 2 nodes
    Solution sol;
    head = sol.rotate(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}

