class Solution {
public:
    
    int n, m, mx;
    
    int dfs( int i, int j, int lp, vector<vector<int>>& mat, vector<vector<int>>& inc ){
        if( (i < 0) || (j < 0) || (j >= m) || (i >= n) || (mat[i][j] <= lp) ){
            return 0;
        }
        if( inc[i][j] != -1 ){
            return inc[i][j];
        }
        
        int ans = dfs( i-1, j, mat[i][j], mat, inc );
        ans = max( ans, dfs( i, j+1, mat[i][j], mat, inc ) );
        ans = max( ans, dfs( i+1, j, mat[i][j], mat, inc ) );
        ans = max( ans, dfs( i, j-1, mat[i][j], mat, inc ) );
        
        ans++;
        mx = max( mx, ans );
        
        return inc[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size(), mx = 0;
        
        vector<vector<int>> inc( n, vector<int>( m, -1 ) );
        
        for( int i =0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if( inc[i][j] == -1 ){
                    int ans = dfs( i-1, j, matrix[i][j], matrix, inc );
                    ans = max( ans, dfs( i, j+1, matrix[i][j], matrix, inc ) );
                    ans = max( ans, dfs( i+1, j, matrix[i][j], matrix, inc ) );
                    ans = max( ans, dfs( i, j-1, matrix[i][j], matrix, inc ) );
                    
                    ans += 1;
                    
                    inc[i][j] = ans;
                }
                mx = max( mx, inc[i][j] );
                //cout<<inc[i][j]<<endl;
            }
        }
        
        return mx;
    }
};