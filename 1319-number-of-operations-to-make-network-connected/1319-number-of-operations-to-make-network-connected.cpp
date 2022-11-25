class Solution {
public:
    
    int find( int a, vector<int>& par ){
        if( par[a] != a ){
            par[a] = find( par[a], par );
        }
        return par[a];
    }
    
    void union_set( int a, int b, vector<int>& par, vector<int>& rank )
    {
        if( rank[a] > rank[b] ){
            par[b] = a;
            rank[a] += rank[b];
        }
        else{
            par[a] = b;
            rank[b] += rank[a];
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> par( n+1 );
        vector<int> rank( n+1, 1 );
        
        for( int i = 0 ; i <= n ; i++ ){
            par[i] = i;
        }
        
        int c = 0, cmp = 0;
        
        for( int i = 0 ; i < connections.size() ; i++ ){
            int u = connections[i][0], v = connections[i][1];
            int p1 = find( u, par), p2 = find( v, par );
            
            if( p1 == p2 ){
                c++;
            }
            else{
                union_set( p1, p2, par, rank );
            }
            
        }
        
        for( int i = 0 ; i < n ; i++ ){
            if( par[i] == i ){
                cmp++;
            }
        }
        
        int ans = cmp - 1;
        if( c >= ans ){
            return ans;
        }
        return -1;
        
    }
};

