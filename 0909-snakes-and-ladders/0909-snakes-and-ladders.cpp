typedef pair< int , int> pi;
typedef pair< pi, vector<int> > pv;

class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), mx= n*n, l2r = 1 , val = 1;
        
        unordered_map< int, vector<int>>mp;
        vector<vector<int>> grid( n, vector<int>(n, 0) );
        vector<vector<bool>> vis( n, vector<bool>(n, false) );
        
        for( int i = n-1 ; i>= 0 ; i-- ){
            if( l2r == 1 ){
                for( int j = 0 ;j < n; j++ ){
                    grid[i][j] = val;
                    mp[val++] = { i, j };
                }
            }
            else{
                for( int j = n-1 ;j >= 0 ; j-- ){
                    grid[i][j] = val;
                    mp[val++] = { i, j };
                }
            }
            l2r ^= 1;
        }
        
        priority_queue< pi, vector<pi>, greater<pi> > pq;
        pq.push({0, 1});
        
        while( !pq.empty() ){
            pi tp = pq.top();
            pq.pop();
            int curr = tp.second, s = tp.first, r = min( mx, curr+6);
            int x = mp[curr][0], y = mp[curr][1];
            
            if( curr == mx ){
                return s;
            }
            if( vis[x][y] ){
                continue;
            }
            vis[x][y] = true;
            
            for( int i = curr + 1 ; i <= r ; i++ ){
                int dx = mp[i][0], dy = mp[i][1];
                //no snake or ladder
                if( board[dx][dy] == -1 ){
                    pq.push({ s+1, grid[dx][dy] });
                }
                //if snake/ ladder present
                else{
                    pq.push({ s+1, board[dx][dy] });
                }
            }
            
        }
        
        return (-1);
    }
};
