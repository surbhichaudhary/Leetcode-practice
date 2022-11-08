class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> sum = mat;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 1; j < m; j++ ){
                sum[i][j] += sum[i][j-1];
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m, 0) );
        
        for( int i = 0 ; i< n ;i++ ){
            int r1 = max( 0, i-k ), r2 = min(n-1, i+k );
            for( int j = 0 ; j< m ; j++ ){
                
                int c1 = max( 0, j-k ), c2 = min( m-1, j+k ), s =0;
                bool sub = ((c1> 0 )? true : false);
                
                for( int x = r1 ; x <= r2 ; x++ ){
                    s += sum[x][c2];
                    if( sub ){
                        s -= sum[x][c1-1];
                    }
                } // x loop
                
                ans[i][j] = s;
            }// j loop
        }// i loop
        
        return ans;
    }
};