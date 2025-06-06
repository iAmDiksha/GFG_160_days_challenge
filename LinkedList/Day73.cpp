#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
    public:
      // Function to remove a loop in the linked list.
      void removeLoop(Node* head) {
          if(head == NULL) return;
          Node* slow = head, *fast = head;
          while(slow && fast && fast->next)
          {
              slow = slow->next;
              fast = fast->next->next;
              
              if(slow == fast)
              {
                  slow = head;
                  if(slow == fast)
                  {
                      while(fast->next != slow)
                      {
                          fast = fast->next;
                      }
                      fast->next = NULL;
                      return;
                  }
                  Node* prev = fast;
                  while(slow != fast)
                  {
                      prev = fast;
                      slow = slow->next;
                      fast = fast->next;
                  }
                  prev->next = NULL;
                  return;
              }
          }
          
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
    // Create a linked list with a loop
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    // Creating a loop for testing
    head->next->next->next->next->next = head->next; // 5 points to 2

    Solution sol;
    sol.removeLoop(head);

    // Print the linked list after removing the loop
    printList(head);

    return 0;
}