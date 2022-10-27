class Solution {
public:
    
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int i1, int j1){
        int n = img1.size(), c1 = 0, c2 = 0, i2 = 0;
        
        for( int i = i1 ; i < n ; i++ ){
            int j2 = 0;
            for( int j = j1 ; j < n ; j++ ){
                if( img1[i][j] == 1 && img2[i2][j2] == 1 ){
                    c1++;
                }
                if( img1[i][j2] == 1 && img2[i2][j] == 1 ){
                    c2++;
                }
                j2++;
             }
            i2++;
        }
        
        return max( c1, c2 );
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                ans = max( ans, overlap( img1, img2, i, j ) );
                ans = max( ans, overlap( img2, img1, i, j ) );
            }
        }
        
        return ans;
    }
};