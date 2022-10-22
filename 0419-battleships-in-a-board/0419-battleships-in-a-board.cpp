class Solution {
public:
    
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid( int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visit ){
        if( i<0 || j<0 || i >= n || j >= m || visit[i][j] || board[i][j] == '.' ){
            return false;
        }
        return true;
    }
    
    void dfs( int i, int j, int k, vector<vector<char>>& board, vector<vector<bool>>& visit ){
        if( !isValid(i, j, board, visit) ){
            return ;
        }
        
        visit[i][j] = true;
        dfs( i+dx[k], j+dy[k], k, board, visit );
        return;
    }
    
    int countBattleships(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        int ans = 0;
        vector<vector<bool>> visit( n, vector<bool>(m, false) );
        
        for( int i = 0 ; i < n ;i++ ){ // row
            for( int j = 0 ; j< m ;j++ ){ //traversal
                if( board[i][j] == 'X' && !visit[i][j] ){ // battleship
                    ans++;
                    visit[i][j] = true;
                    for( int k = 0 ; k < 4 ; k++ ){  // adjacent 
                        if( isValid( i+dx[k], j+dy[k], board, visit ) ){ //
                            dfs( i+dx[k], j+dy[k], k, board, visit );
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};