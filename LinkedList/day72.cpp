#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
      Node* findFirstNode(Node* head) {
          Node* slow = head, *fast = head;
          while(slow && fast && fast->next)
          {
              slow = slow->next;
              fast = fast->next->next;
              
              if(fast == slow)
              {
                  slow = head;
                  while(slow!=fast)
                  {
                      slow = slow->next;
                      fast = fast->next;
                  }
                  return slow;
              }
          }
          return new Node(-1);
      }
  };

// Function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    head->next->next->next->next->next = head->next;

    Solution sol;
    Node* firstNode = sol.findFirstNode(head);
    
    if(firstNode->data != -1)
        cout << "First node in loop: " << firstNode->data << endl;
    else
        cout << "No loop detected." << endl;

    return 0;
}
