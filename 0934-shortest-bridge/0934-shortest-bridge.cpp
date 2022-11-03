typedef pair<int, int> pi;
typedef pair< int, pi> pii;

class Solution {
public:
    
    int n;
    
    void bfs( int i, int j, vector<vector<int>>& grid, 
             priority_queue< pii, vector<pii>, greater<pii> >& pq ){
        if( i<0 || j<0 || i>= n || j>= n || ( grid[i][j] != 1 )  ) {
            return;
        }
        
        pq.push({ 0, { i, j }});
        grid[i][j] = 2;
        
        bfs( i-1, j, grid, pq );
        bfs( i, j+1, grid, pq );
        bfs( i+1, j, grid, pq );
        bfs( i, j-1, grid, pq );
    }
    
    void dfs( int i, int j, vector<vector<int>>& grid, set<pi>& mp ){
        if( i<0 || j<0 || i>= n || j>= n || ( grid[i][j] != 1 )  ) {
            return;
        }
        
        mp.insert({ i,j });
        grid[i][j] = 2;
        
        dfs( i-1, j, grid, mp );
        dfs( i, j+1, grid, mp );
        dfs( i+1, j, grid, mp );
        dfs( i, j-1, grid, mp );
        
    } 
    
    bool isValid( int i, int j, vector<vector<bool>>& vis ){
        if( i < 0 || i >= n || j< 0 || j>= n || vis[i][j] ){
            return false;
        }
        return true;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool flag = false;
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        set< pi > i2;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( grid[i][j] == 1 ){
                    if( flag ){
                        dfs( i, j, grid, i2 );
                    }
                    else{
                        flag = true;
                        bfs( i, j, grid, pq );
                    }
                    
                }
            }
        }
        
        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, 1, 0, -1 };
        
        vector<vector<bool>> vis(n, vector<bool>( n, false) );
        
        while( !pq.empty() ){
            pii tp = pq.top();
            pq.pop();
            int r = tp.second.first, c = tp.second.second, f = tp.first;
            
            if( i2.find(tp.second) != i2.end() ){
                return (f-1);
            }
            if( vis[r][c] ){
                continue;
            }
            vis[r][c] = true;
            
            for( int i =0 ; i< 4 ; i++ ){
                if( isValid( r+dx[i], c+dy[i], vis ) ){
                    int x = r+dx[i], y = c+dy[i];
                    pq.push({ f+1, { x, y }});
                }
            }
        }
        
        return -1;
    }
};