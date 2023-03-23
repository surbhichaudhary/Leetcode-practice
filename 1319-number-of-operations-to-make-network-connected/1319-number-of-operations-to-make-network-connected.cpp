class Solution {
public:
    
    int findParent( int v, vector<int>& par ){
        if( par[v] == v ){
            return v;
        }
        return par[v] = findParent( par[v], par );
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> par;
        vector<int> rank(n, 1);
        for( int i = 0 ; i < n ; i++ ){
            par.push_back(i);
        }
        
        int extra_cab = 0;
        
        for( int i = 0 ; i < connections.size() ; i++ ){
            int v1 = connections[i][0], v2 = connections[i][1];
            int p1 = findParent( v1, par ), p2 = findParent( v2, par );
            
            if( p1 != p2 ){
                if( rank[p1] < rank[p2] ){
                    swap(p1, p2 );
                }
                
                par[p2] = p1;
                rank[p1] += rank[p2];
            }
            else{
                extra_cab++;
            }
            
        }
        
        int cc = 0;
        for( int i = 0 ; i< n ; i++ ){
            if( par[i] == i ){
                cc++;
            }
        }
        
        if( extra_cab < cc-1 ){
            return (-1);
        }
        
        return ( cc-1 );
    }
};