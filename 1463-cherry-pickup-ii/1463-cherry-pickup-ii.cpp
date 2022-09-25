typedef long long ll;

class Solution {
public:
    int n,m;
    
    int solve( int i, int j1, int j2, vector<vector<int>>& grid,
            vector<vector<vector<ll>>>& t ){
        if( j1 < 0 || j2 < 0 || j1 >= m || j2 >= m )
            return (-1e7);
        
        if( i == n-1 ){
            if( j1 == j2 ){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        
        if( t[i][j1][j2] != -1 )
            return t[i][j1][j2];
        
        int ans = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2], mx =0;
        
        for( int a = -1 ; a <= 1 ; a++ ){
            for( int b = -1 ; b <= 1 ; b++ ){
                mx = max( mx, solve( i+1, j1 + a, j2 + b, grid, t ) );
            }
        }
        
        return ( t[i][j1][j2] = ans + mx );
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<ll>>> t( n+1,vector<vector<ll>>(m+1,vector<ll>(m+1, -1)));
        
        return solve( 0, 0, m-1, grid, t );
    }
};