class Node{
    public:
    
    string val;
    Node* next;
    Node* prev;
    
    Node( string v ){
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
public:
    
    Node* curr;
    
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* nw = new Node(url);

        curr->next = nw;
        nw->prev = curr;
        curr = nw;
    }
    
    string back(int steps) {
        for( int i = 0 ; curr->prev && (i < steps) ; i++ ){
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        for( int i = 0 ; (i < steps) && curr->next ; i++ ){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */