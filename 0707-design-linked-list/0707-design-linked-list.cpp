class Node {
public:
    int val;
    Node* next;
 
    // Default constructor
    Node()
    {
        val = 0;
        next = NULL;
    }
 
    // Parameterised Constructor
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    
    Node* head;
    int n;
    
    MyLinkedList() {
        head = NULL;
        n = 0;
    }
    
    int get(int index) {
        if( index >= n ) return (-1);
        
        Node* t = head;
        for( int i = 0 ; t && (i < index) ; i++ ){
            t = t->next;
        }
        return t->val;
    }
    
    void addAtHead(int val) {
        Node* nw = new Node(val);
        nw->next = head;
        head = nw;
        n++;
    }
    
    void addAtTail(int val) {
        Node* nw = new Node(val);
        n++;
        if( !head ){
            head = nw;
            return;
        }
        
        Node* t = head;
        while( t->next ){
            t = t->next;
        }
        t->next = nw;
    }
    
    void addAtIndex(int index, int val) {
        if( index == 0 ){
            addAtHead(val);
            return;
        }
        if( index == n ){
            addAtTail(val);
            return;  
        }
        if( index > n ) return;
        
        Node* nw = new Node(val);
        Node* t = head;
        for( int i = 1 ; t && (i < index) ; i++ ){
            t = t->next;
        }
        nw->next = t->next;
        t->next = nw;
        n++;
        return;
    }
    
    void deleteAtIndex(int index) {
        if( index >= n ) return;
        if( index == 0 ) {
            head = head->next;
            n--;
            return;
        }
        
        Node* t = head;
        for( int i = 0 ; t && (i < index-1) ; i++ ){
            t = t->next;
        }
        t->next = t->next->next;
        n--;
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */