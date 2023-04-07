class Solution {
public:
    
    int n,m;
    
    void dfs( int i, int j, vector<vector<int>>& grid ){
        if( i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1 ){
            return ;
        }
        
        grid[i][j] = 2;
        dfs( i-1, j, grid );
        dfs( i+1, j, grid );
        dfs( i, j-1, grid );
        dfs( i, j+1, grid );
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        //mark cells touching boundary
        for( int i = 0 ; i < n ; i++ ){
            if( grid[i][0] == 1 ){
                dfs( i, 0, grid );
            }
            if( grid[i][m-1] == 1 ){
                dfs( i, m-1, grid );
            }
        }
        for( int i = 0 ; i < m ; i++ ){
            if( grid[0][i] == 1 ){
                dfs( 0, i, grid );
            }
            if( grid[n-1][i] == 1 ){
                dfs( n-1, i, grid );
            }
        }
        
        int ans = 0;
        for( int i = 0 ; i < n ;i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if( grid[i][j] == 1 ){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};