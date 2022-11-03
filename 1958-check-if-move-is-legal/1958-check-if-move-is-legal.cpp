class Solution {
public:
    
    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    
    bool isGood( int i, int j, int k, char c, vector<vector<char>>& board ){
        if( i<0 || i>=8 || j<0 || j>= 8 || (board[i][j] == '.') ){
            return false;
        }
        if( board[i][j] == c ){
            return true;
        }
        
        return isGood( i+dx[k], j+dy[k], k, c, board );
    }
    
    bool isValid( int i, int j, char c, vector<vector<char>>& board ){
        if( i<0 || i>=8 || j<0 || j>= 8 || (board[i][j] != c ) ){
            return false;
        }
        return true;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char req = ((color == 'B') ? 'W' : 'B' );
        
        for( int i = 0 ; i < 8 ; i++ ){
            int x = rMove + dx[i], y = cMove + dy[i];
            if( isValid( x, y, req, board ) ){
                if( isGood(x+dx[i], y+dy[i], i, color, board) ){
                    return true;
                }
            }
        }
        
        return false;
    }
};