typedef vector<vector<int>> vvi;

class Solution {
public:
    
    int n, m, mod = 1000000007;
    
    int solve( int i, int j, int sum, vvi& grid, int k, vector<vvi>& dp ){
        if( i<0 || j <0 || i >= n || j >= m ){
            return 0;
        }
        
        sum += grid[i][j];
        if( sum > k ){
            sum %= k ;
        }
        
        if( i == n-1 && j == m-1 ){
            if( sum%k == 0 ){
                return 1%mod;
            }
            return 0;
        }
        if( dp[i][j][sum] != -1 ){
            return dp[i][j][sum];
        }
        
        return dp[i][j][sum] = ( solve( i+1, j, sum, grid, k, dp )%mod + 
                 solve( i, j+1, sum, grid, k, dp )%mod )%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vvi> dp( n, vvi(m, vector<int>( k+1, -1 ) ) );
        
        for( int i =0 ; i < n ;i++ ){
            for( int j = 0 ; j < m ; j++ ){
                grid[i][j] %= k;
            }
        }
        
        return solve( 0, 0, 0, grid, k, dp );
    }
};