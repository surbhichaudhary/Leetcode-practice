struct Node {
  int val;
  Node* next;
  Node* prev;

  Node() : val(0), next(nullptr), prev(nullptr) {}
  Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyCircularQueue {
public:
    
    Node* head;
    Node* tail;
    int s, n;
    
    MyCircularQueue(int k) {
        head = tail = NULL;
        s = k;
        n = 0 ;
    }
    
    bool enQueue(int value) {
        if( n == s ) return false;
        Node* p = new Node(value);
        
        if( !head ){
            head = p;
        }
        else{
            tail->next = p;
        }
        tail = p;
        n++;
        return true;
    }
    
    bool deQueue() {
        if( n == 0 ) return false;
        Node* p = head;
        head = head->next;
        delete p;
        n--;
        return true;
    }
    
    int Front() {
        if( n == 0 ) return -1;
        return head->val;
    }
    
    int Rear() {
        if( n == 0 ) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (n == 0);
    }
    
    bool isFull() {
        return ( n == s );
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */