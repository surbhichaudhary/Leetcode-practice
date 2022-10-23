class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for( int i = 0 ; i < n-2 ; i++ ){
            for( int j = 0 ; j < m -2 ; j++ ){
                unordered_map<int , int> mp;
                mp[grid[i][j]]++;      mp[grid[i][j+1]]++;      mp[grid[i][j+2]]++ ; 
                mp[grid[i+1][j]]++;    mp[grid[i+1][j+1]]++;    mp[grid[i+1][j+2]]++ ;
                mp[grid[i+2][j]]++ ;   mp[grid[i+2][j+1]]++ ;   mp[grid[i+2][j+2]]++ ;
                
                
                if( grid[i][j] > 9   || grid[i][j+1] > 9   ||  grid[i][j+2] > 9   ||
                    grid[i+1][j] > 9 || grid[i+1][j+1] > 9 ||  grid[i+1][j+2] > 9 ||
                    grid[i+2][j] > 9 || grid[i+2][j+1] > 9 ||  grid[i+2][j+2] > 9 ||
                    mp.size() < 9    || 
                    grid[i][j] < 1   || grid[i][j+1] < 1   ||  grid[i][j+2] < 1   ||
                    grid[i+1][j] < 1 || grid[i+1][j+1] < 1 ||  grid[i+1][j+2] < 1 ||
                    grid[i+2][j] < 1 || grid[i+2][j+1] < 1 ||  grid[i+2][j+2] < 1 ){
                    continue;
                }
                //first row
                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                //second row
                int r = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                if( r != s ){
                    continue;
                }
                //third row
                r = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                if( r != s ){
                    continue;
                }
                //first column
                r = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                if( r != s ){
                    continue;
                }
                //second col
                r = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                if( r != s ){
                    continue;
                }
                //third col
                r = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                if( r != s ){
                    continue;
                }
                //first diagonal
                r = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                if( r != s ){
                    continue;
                }
                //second diagonal
                r = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if( r != s ){
                    continue;
                }
                ans++;
            }
        }
        
        return ans;
    }
};