#define mod 1000000007
typedef long long ll;

class Solution {
public:
    
    ll n, m, ans;

    ll dfs( int i, int j, int lp, vector<vector<int>>& mat, vector<vector<ll>>& inc ){
        if( (i < 0) || (j < 0) || (j >= m) || (i >= n) || (mat[i][j] <= lp) ){
            return 0;
        }
        if( inc[i][j] != -1 ){
            return inc[i][j];
        }
        
        ll s1 = dfs( i-1, j, mat[i][j], mat, inc );
        ll s2 = dfs( i, j+1, mat[i][j], mat, inc );
        ll s3 = dfs( i+1, j, mat[i][j], mat, inc );
        ll s4 = dfs( i, j-1, mat[i][j], mat, inc );
       
        return inc[i][j] = ( 1%mod + s1%mod + s2%mod + s3%mod + s4%mod )%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), ans = 0;
        int t = n*m;
        
        vector<vector<ll>> inc( n, vector<ll>( m, -1 ) );
        
        for( int i =0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if( inc[i][j] == -1 ){
                    int curr = dfs( i, j, -1, grid, inc );
                }
            }
        }
        
        for( int i =0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                ans = ( ( ans%mod ) + ( inc[i][j]%mod ) )%mod;
            }
        }
        
        return ans;
    }
};
