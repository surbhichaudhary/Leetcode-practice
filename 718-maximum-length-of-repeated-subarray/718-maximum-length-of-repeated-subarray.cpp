class Solution {
public:
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), ans = 0;
        
        vector<vector<int>> t (n1+1, vector<int>( n2+1, 0) );
        for( int i=0 ; i <= n1; i++ ){
            for( int j = 0; j <= n2; j++ ){
                if( i == 0 || j == 0 ){
                    
                }
                else if( nums1[i-1] == nums2[j-1] ){
                    t[i][j] = 1+ t[i-1][j-1];
                    ans = max( ans, t[i][j] );
                }
                else{
                    t[i][j] = 0 ;
                }
            }
        }
        
        return ans;
    }
};
