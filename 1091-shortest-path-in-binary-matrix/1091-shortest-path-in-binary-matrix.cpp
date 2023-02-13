typedef long long ll;
typedef vector<ll> vl;

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ll n = grid.size(), ans = 10001;
        int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
        int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
        
        if( (grid[0][0] == 1) || (grid[n-1][n-1] == 1) )
            return (-1);
        
        queue< vl > q;
        q.push({ 1, 0, 0 });
        
        vector<vector<bool>> vis( n, vector<bool>(n, false ));
        
        while( !q.empty() ){
            ll x = q.front()[1], y = q.front()[2], d = q.front()[0];
            q.pop();
            
            if( (x == n-1) && (y == n-1) ){
                ans = min( ans, d );
                continue;
            }
            
            if( vis[x][y] ){
                continue;
            }
            
            vis[x][y] = true;
            
            for( int i = 0 ; i < 8 ; i++ ){
                int a = x+dx[i], b = y+dy[i];
                if((a>=0) && (a<n) && (b>= 0) && (b<n) && (grid[a][b]==0) && (!vis[a][b])){
                    q.push({ 1+d, a, b });
                }
            }
        }
        
        return (( ans <= 10000 ) ? ans : -1 );
    }
};

