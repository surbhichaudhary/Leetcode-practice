typedef pair<int, int> pi;

class Solution {
public:
    int n,m,r,c;
    
    bool isValid( int i, int j, vector<vector<char>>& maze, vector<vector<bool>>& vis){
        if( i<0 || i>=n || j<0 || j>=m || (i==r && j==c) || vis[i][j] || maze[i][j] == '+' ){
            return false;
        }
        return true;
    }
    
    bool isBoundary( int i, int j ){
        if( i == 0 || i == n-1 || j == 0 || j == m-1 ){
            return true;
        }
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size(), m = maze[0].size(), r = entrance[0], c = entrance[1] ;
        vector<vector<bool>> vis(n, vector<bool>(m, false) );
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX) );
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        queue<pi> q;
        q.push({ r, c });
        vis[r][c] = true;
        dis[r][c] = 0;
        
        while( !q.empty() ){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            if( isValid( x, y, maze, vis) && isBoundary(x,y) )
                return dis[x][y];
            
            for( int i =0 ;i < 4; i++ ){
                if( isValid( x+dx[i], y+dy[i], maze, vis ) ){
                    q.push({ x+dx[i], y+dy[i] });
                    dis[x+dx[i]][y+dy[i]] = 1 + dis[x][y];
                    vis[x+dx[i]][y+dy[i]] = true;
                    
                    if( isBoundary( x+dx[i], y+dy[i] ) )
                        return dis[x+dx[i]][y+dy[i]];
                }
            }
        }
        
        return -1;
    }
};