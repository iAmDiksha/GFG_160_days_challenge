#include<bits/stdc++.h>
using namespace std;

/* Linked List Node structure:*/
struct Node
{
    int data;
    struct Node *next;
};

class Solution {
    public:
      Node* reverseList(struct Node* head) {
          if(head == NULL)
          {
              return head;
          }
          stack <Node*> st;
          Node* temp = head;
          while(temp->next != NULL)
          {
             st.push(temp);
             temp = temp->next;
          }
          head = temp;
          while(!st.empty())
          {
              
              temp->next = st.top();
              st.pop();
              temp = temp->next;
          }
          temp->next=NULL;
          return head;
      }
  };

// Function to create a new node with given data
Node* newNode(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
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

    cout << "Original Linked List: ";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}

  