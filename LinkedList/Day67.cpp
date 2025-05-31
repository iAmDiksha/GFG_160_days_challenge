#include <bits/stdc++.h>
using namespace std;

/* Link list Node*/
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
      Node* sortedMerge(Node* head1, Node* head2) {
          if(!head1)
          {
              return head2;
          }
          if(!head2) return head1;
          
          Node* head = head1->data < head2->data ? head1: head2;
          Node* temp1 = head1;
          Node* temp2 = head2;
          Node* temp = head;
          if(head == head1){
              temp1 = temp1->next;
          }
          else{
              temp2 = temp2->next;
          }
          while(temp1 != NULL && temp2 != NULL)
          {
              if(temp1->data < temp2->data)
              {
                  temp->next = temp1;
                  temp1 = temp1->next;
              }
              else{
                  temp->next = temp2;
                  temp2 = temp2->next;
              }
              temp = temp->next;
          }
          if(temp1 != NULL)
          {
               temp->next = temp1;
              
          }
          if(temp2 != NULL)
          {
               temp->next = temp2;
             
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
    // Create two linked lists 1->3->5 and 2->4->6
    Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);

    Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);

    Solution sol;
    Node* mergedHead = sol.sortedMerge(head1, head2);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
// This code merges two sorted linked lists into one sorted linked list.
// The merged list is printed at the end.