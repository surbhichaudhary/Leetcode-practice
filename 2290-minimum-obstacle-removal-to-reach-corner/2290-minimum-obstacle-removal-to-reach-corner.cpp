typedef long long ll;

class Solution {
public:
    
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    int n, m;
    
    bool isValid( int i, int j, int cst, vector<vector<ll>>& t, vector<vector<int>>& grid, 
               vector<vector<bool>>& vis ){
        if( i < 0 || j <0 || i >=n || j >= m || cst + grid[i][j]  >= t[i][j] || vis[i][j] ){
            return false;
        }
        return true;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<ll>> t(n, vector<ll>(m, INT_MAX) );
        vector<vector<bool>> vis(n, vector<bool>(m, false) );
        
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>> > q;
        q.push( {0,0,0} );
        t[0][0] = 0;
        
        while( !q.empty() ){
            auto fr = q.top();
            int cst = fr[0], r = fr[1], c = fr[2];
            q.pop();
            vis[r][c] = true;
            
            if( r == n-1 && c == m-1 ){
                return t[r][c];
            }
            
            for( int i = 0 ; i < 4 ; i++ ){
                int x = r+dx[i], y = c+dy[i];
                if( isValid( x, y, cst, t, grid, vis ) ){
                    t[x][y] = cst + grid[x][y] ;
                    q.push( { t[x][y], x, y } );
                }
            }
            
        }
        
        return t[n-1][m-1];
    }
};