// C++ program to implement LRU Least Recently Used)
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key, value;
    Node* next, *prev;
    Node(int k,int v){
        key =k; value = v;
        next=NULL; prev = NULL;
    }
};

class LRUCache {
  private:
  int capacity;
  unordered_map<int,Node*> cacheMap;
  Node* head;
  Node* tail;
  public:
    LRUCache(int cap) {
        this->capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(cacheMap.find(key)==cacheMap.end()) 
        return -1;
        
        Node* node = cacheMap[key];
        remove(node);
        add(node);
        return node->value;
        // code here
    }

        
    void put(int key, int value) {
        // code here
        if(cacheMap.find(key) !=cacheMap.end()) 
        {
            Node* oldNode = cacheMap[key];
            remove(oldNode);
            delete oldNode;
        }
        Node *node = new Node(key,value);
        cacheMap[key] = node;
        add(node);
        
        if(cacheMap.size() > capacity)
        {
            Node* nodeToDelete = tail->prev;
            remove(nodeToDelete);
            cacheMap.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }
    
    void add(Node* node){
        Node* nxt = head->next;
        head->next = node;
        node->prev=head;
        node->next = nxt;
        nxt->prev = node;
    }
    
    void remove(Node* node)
    {
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }
};

int main(){
    LRUCache cache(2);
  
    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
