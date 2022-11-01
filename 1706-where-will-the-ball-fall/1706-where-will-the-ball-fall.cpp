class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<int> ans( m );
        
        for( int c = 0 ; c < m ; c++ ){
            int curr = c ;
            for( int r = 0 ; r < n ; r++ ){
                int np = curr + grid[r][curr];
                
                if( np < 0 || np >= m || grid[r][curr] != grid[r][np] ){
                    ans[c] = -1;
                    break;
                }
                
                curr = np;
                ans[c] = np;
            }
        }
        
        return ans;
    }
};