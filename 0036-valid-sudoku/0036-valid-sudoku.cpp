class Solution {
public:
    
    bool isrow( int i, int j, vector<vector<char>>& board )
    {
        for( int x = i+1 ; x < 9 ; x++ ){
            if( board[x][j] == board[i][j] ){
                //cout<<"row"<<x<<"row "<<i<<" col"<<j<<"\n";
                return false;
            }
        }
        return true;
    }
    
    bool iscol( int i, int j, vector<vector<char>>& board  )
    {
        for( int x = j+1 ; x < 9 ; x++ ){
            if( board[i][x] == board[i][j] ){
                //cout<<"col"<<x<<"row "<<i<<" col"<<j<<"\n";
                return false;
            }
        }
        return true;
    }
    
    bool isSub( int i, int j, vector<vector<char>>& board )
    {
        int r, c;
        if( i<3 ){ r = 0;}
        else if( (i >= 3) && (i < 6) ){ r = 3;}
        else {r = 6;}
        
        if( j < 3 ){ c = 0;}
        else if( (j>=3) && (j< 6) ){ c = 3;}
        else {c = 6;}
        
        for( int x = r ; x < r+3 ; x++ ){
            for( int y = c ; y < c+3 ; y++ ){
                if( (x == i) && (y == j) ){
                    continue;
                }
                if( board[x][y] == board[i][j] ){
                    //cout<<"box"<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for( int i = 0 ; i < 9 ; i++ ){
            for( int j = 0 ; j < 9; j++ ){
                if( board[i][j] != '.' )
                {
                    
                    if( !isrow(i,j, board)  ){
                        return false;
                    }
                    if( !iscol(i, j, board)  ){
                        return false;
                    }
                    if( !isSub( i, j, board) ){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


/**#include<set>

class Solution {
    int cols[9] = {}, rows[9]={}, grid[3][3] = {};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( int i = 0 ; i < 9 ; i++ ){
            for( int j = 0 ; j < 9; j++ ){
                if( board[i][j] != '.' ){
                    int m = 1<<(board[i][j] - '1' );
                    if( rows[i]&m || cols[j]&m || grid[i/3][j/3]&m ){
                        return false;
                    }
                    rows[i] ^= m;
                    cols[j] ^= m;
                    grid[i/3][j/3] ^= m;
                }
            }
        }
        return true;
    }
};*/