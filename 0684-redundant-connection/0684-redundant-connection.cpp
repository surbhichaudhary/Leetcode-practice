class Solution {
public:
    
    int find( int a, vector<int>& par ){
        if( par[a] != a ){
            par[a] = find( par[a], par );
        }
        return par[a];
    }
    
    void union_set( int a, int b, vector<int>& par, vector<int>& rank ){
        if( par[a] == par[b] ){
            return;
        }
        if( rank[a] >= rank[b] ){
            par[b] = a;
            rank[a] += rank[b];
        }
        else{
            par[a] = b;
            rank[b] += rank[a];
        }
        return;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> par( 1001 );
        vector<int> rank(1001, 1);
        
        for( int i =0 ; i<= 1000 ; i++ ){
            par[i] = i;
        }
        
        for( int i = 0; i < edges.size() ; i++ ){
            int u = edges[i][0], v = edges[i][1];
            int p1 = find( u, par ), p2 = find( v, par );
            
            if( p1 == p2 ){
                return edges[i];
            }
            
            union_set( p1, p2, par, rank );
        }
        
        return ans;
    }
};

