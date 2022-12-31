class Solution {
public:
    
    int no, ans, n, m, sr, sc;
    
    void path( int i, int j, int p, vector<vector<int>>& grid ){
        if( (i < 0) || (i >= n) || (j < 0) || (j >= m) || (grid[i][j] == -1) ){
            return;
        }
        
        if( grid[i][j] == 2 ){
            if( p == no ){
                ans++;
            }
            return;
        }
        
        if( grid[i][j] == 0 ){
            p++;
        }

        int v = grid[i][j];
        grid[i][j] = -1;
        
        path( i-1, j, p, grid );
        path( i, j+1, p, grid );
        path( i+1, j, p, grid );
        path( i, j-1, p, grid );
        
        grid[i][j] = v;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        ans = 0, no = 0, n = grid.size(), m = grid[0].size() ;
        
        for( int i = 0; i < n ;i++ ){
            for( int j = 0; j < m ;j++ ){
                if( grid[i][j] == 1 ){
                    sr = i;
                    sc = j;
                }
                else if( grid[i][j] == 0 ){
                    no++;
                }
            }
        }
        
        path( sr, sc, 0, grid );
        
        return ans;
    }
};