class Solution {
public:
    
    bool isSafe( int r, int c, int n , vector<vector<char>>& pos ){
        for( int i = 0 ; i < r ; i++ ){
            if( pos[i][c] == 'N' ){
                return false;
            }
        }
        for( int i = r-1, j = c-1 ; i >= 0 && j >= 0 ; i--, j-- ){
            if( pos[i][j] == 'N' ){
                return false;
            }
        }
        for( int i = r-1, j = c+1 ; i >= 0 && j < n ; i-- , j++ ){
            if( pos[i][j] == 'N' ){
                return false;
            }
        }
        return true;
    }
    
    int solve( int i, int n, vector<vector<char>>& pos){
        if( i >= n ){
            return 1;
        }
        
        int ans = 0;
        
        for( int j = 0 ; j < n ; j++ ){
            if( isSafe( i, j, n, pos ) ){
                pos[i][j] = 'N';
                ans += solve( i+1, n, pos );
                pos[i][j] = '.';
            }
        }
        
        return ans;
    }
    
    int totalNQueens(int n) {
        
        vector<vector<char>> pos( n, vector<char>(n, '.' ) );
        return solve( 0, n, pos );
        
    }
};
