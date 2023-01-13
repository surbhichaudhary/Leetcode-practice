typedef pair<char, int> ci;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    
    ci solve( Node* root, string& s, int& ans ){
        if( !root ){
            return { '#', 0 };
        }
        
        int st = 0;
        ci tmp = { s[root->val], 1 };
        priority_queue<int, vector<int>, greater<int> > pq;

        for( int i = 0 ; i < root->children.size() ; i++ ){
            ci curr = solve( root->children[i], s, ans );
            if( curr.first != s[root->val] ){
                pq.push( curr.second );
                tmp.second = max( tmp.second, 1 + curr.second );
                
                if( pq.size() > 2 ){
                    pq.pop();
                }
            }
        }
        
        while( !pq.empty() ){
            st += pq.top();
            pq.pop();
        }
        
        ans = max( ans, max( tmp.second, st+1) );
        return tmp;
    }
    
    int longestPath(vector<int>& parent, string& s) {
        int n = parent.size();
        if( n < 2 ){
            return n;
        }
        
        unordered_map<int, Node*> mp;
        Node* root = new Node(0);
        mp[0] = root;
        //make tree
        for( int i = 1 ; i < n ; i++ ){
            int p = parent[i];
            Node* a ;  Node* b;
            
            if( mp.count(p) ) {
                a = mp[p];
            }
            else {
                a = new Node(p); 
                mp[p] = a;
            }
            
            if( mp.count(i) ){
                b = mp[i];
            }
            else{ 
                b = new Node(i);
                mp[i] = b;
            }
            
            a->children.push_back(b);
        }
        
        int ans = 1, sm =0 ;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for( int i =0 ; i < root->children.size() ; i++ ){
            ci curr = solve( root->children[i], s, ans );
            
            if( curr.first != s[0] ){
                ans = max( ans, 1 + curr.second );
                pq.push( curr.second);
                
                if( pq.size() > 2 ){
                    pq.pop();
                }
            }
            
        }
        
        while( !pq.empty() ){
            sm += pq.top();
            pq.pop();
        }
        ans = max( ans, sm+1 );
        
        return ans;
    }
};
