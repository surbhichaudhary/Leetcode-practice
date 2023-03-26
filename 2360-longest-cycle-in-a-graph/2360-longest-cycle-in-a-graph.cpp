typedef pair<int, int> pi;

class Solution {
public:
    
    int res;
    
    pi dfs( int v, vector<bool>& vis, vector<int>& edges){
        if( vis[v] ){
            return { v, 0};//start node of cycle & nodes in cycle
        }
        
        vis[v] = true;
        
        if( edges[v] == -1 ){
            return { -1, 0 };
        }
        
        pi sm = dfs( edges[v], vis, edges );
        (sm.second) += 1;
        
        if( sm.first == v ){
            res = max( res, sm.second );
        }
        
        return sm ;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        res = -1;
        vector<bool> vis( n, false );
        
        for( int i = 0 ; i < n ; i++ ){
            if( !vis[i] ){
                pi sm = dfs( i, vis, edges );
                if( sm.first == i ){
                    res = max( res, sm.second );
                }
            }
        }
        
        if( res == 0 )
            return (-1);
        return res;
    }
};