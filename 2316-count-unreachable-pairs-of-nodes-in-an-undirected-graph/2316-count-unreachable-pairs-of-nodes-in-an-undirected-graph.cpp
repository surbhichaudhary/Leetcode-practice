typedef long long ll;

class Solution {
public:
    
    int find( int v, vector<int>& par ){
        if( par[v] == v ){
            return v;
        }
        return par[v] = find( par[v], par );
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> par;
        vector<ll> rank( n, 1 );
        vector<ll> cc;
        long long ans = 0;
        
        for( int i = 0 ; i < n ;i++ ){
            par.push_back(i);
        }
        
        for( int i = 0 ; i < edges.size() ; i++ ){
            int p1 = find( edges[i][0], par );
            int p2 = find( edges[i][1], par );
            
            if( p1 != p2 ){
                if( rank[p1] < rank[p2] ){
                    swap( p1, p2 );
                }
                par[p2] = p1;
                rank[p1] += rank[p2];
            }
            
        }
        
        for( int i = 0 ; i < n ; i++ ){
            if( par[i] == i ){
                cc.push_back(rank[i]);
            }
        }
        
        vector<ll> lft(n, 0 );
        vector<ll> rgt(n, 0 );
        
        for( int i = 1 ;i < cc.size() ; i++ ){
            lft[i] = lft[i-1] + cc[i-1];
        }
        
        for( int i = cc.size() - 2 ; i >= 0 ; i-- ){
            rgt[i] = rgt[i+1] + cc[i+1];
        }
        
        for( int i = 0 ;i < cc.size() ; i++ ){
            ans += (( lft[i]*cc[i] ) + ( rgt[i] *cc[i] ));
        }
        
        return ans/2;
    }
};
