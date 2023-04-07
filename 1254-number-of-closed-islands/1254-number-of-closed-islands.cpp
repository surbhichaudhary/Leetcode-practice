class Solution {
public:
    
    int n, m;
    
    void bound( int i, int j, vector<vector<int>>& grid ){
        if( i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0 ){
            return ;
        }
        
        grid[i][j] = 2;
        
        bound( i-1, j, grid );
        bound( i+1, j, grid );
        bound( i, j-1, grid );
        bound( i, j+1, grid );
        
    }
    
    void dfs( int i, int j, vector<vector<int>>& grid , vector<vector<bool>>& vis  ){
        if( i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0 ){
            return ;
        }
        
        vis[i][j] = true;
        
        bound( i-1, j, grid );
        bound( i+1, j, grid );
        bound( i, j-1, grid );
        bound( i, j+1, grid );
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis( n, vector<bool>( m, false ) );
        
        for( int i = 0 ; i < n ; i++ ){
            if( grid[i][0] == 0 ){
                bound( i, 0, grid );
            }
            if( grid[i][m-1] == 0 ){
                bound( i, m-1, grid );
            }
        }
        for( int i = 0 ; i < m ; i++ ){
            if( grid[0][i] == 0 ){
                bound( 0, i, grid );
            }
            if( grid[n-1][i] == 0 ){
                bound( n-1, i, grid );
            }
        }
        
        int ans = 0;
        for( int i = 1 ; i < n ; i++ ){
            for( int j = 1 ; j < m ; j++ ){
                if( grid[i][j] == 0 && !vis[i][j] ){
                    dfs( i, j, grid, vis );
                    ans++;
                }
            }
        } 
        
        return ans;
    }
};
