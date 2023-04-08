/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if( !node )
            return NULL;

        Node* nw = new Node( node->val );
        if( node->neighbors.size() == 0 )
            return nw;
        
        unordered_map< int, Node* > mp;
        unordered_map< int, unordered_set<int>> edge;
        vector< bool > vis(101, false );
        queue<Node*> q;
        q.push(node);
        
        mp[1] = nw;
        
        while( !q.empty() ){
            Node* fr = q.front();
            Node* cpy = mp[fr->val];
            q.pop();
            
            if( vis[fr->val] )
                continue;

            vis[fr->val] = true;
            for( int i = 0; i < fr->neighbors.size() ; i++ ){
                Node* curr = fr->neighbors[i];
                q.push(curr);
                Node* adj ;
       
                if( !mp.count( curr->val ) ){
                    adj = new Node( curr->val );
                    mp[curr->val] = adj;
                }
                else{
                    adj = mp[curr->val];
                }
                
                if( edge[cpy->val].find( adj->val) == edge[cpy->val].end() ){
                    cpy->neighbors.push_back( adj );
                    edge[cpy->val].insert( adj->val );
                }
                
                if( edge[adj->val].find( cpy->val) == edge[adj->val].end() ){
                    adj->neighbors.push_back( cpy );
                    edge[adj->val].insert( cpy->val );
                }
                
            }
        }
        
        return nw;
    }
};