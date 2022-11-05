struct Node {
    int val;
    Node *next;
    
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
    
public:
    
    Node* head = NULL;
    Node* tail = NULL;
    
    vector<int> processQueries(vector<int>& queries, int m) {
        //create permutaion
        for( int i = 1 ; i<=m ; i++ ){
            Node* p = new Node(i);
            //cout<<i<<" ";
            
            if( head == NULL ){
                head = p;
            }
            else{
                tail->next = p;
            }
            tail = p;
        }
        
        vector<int> ans;
        //process the queries
        for( int i =0 ; i < queries.size() ; i++ ){
            int curr = queries[i], pos = 0;
            
            if( head->val == curr ){
                ans.push_back(0);
            }
            else{
                Node* t = head;
                while( t && t->next && ( t->next->val != curr )){
                    pos++;
                    t = t->next;
                }
                
                Node* fr = t->next; 
                t->next = fr->next;
                
                fr->next = head;
                head = fr;
                
                ans.push_back(1+pos);
                
            }
        }
        return ans;
    }
};