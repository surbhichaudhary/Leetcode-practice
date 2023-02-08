class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp( n, n+1 );
        
        dp[n-1] = 0;
        for( int i = n-2 ; i >= 0 ; i-- ){
            if( i + nums[i] >= n-1 ){
                dp[i] = 1;
            }
            else{
                for( int j = i+1 ; (j < n) && (j <= (i+nums[i])) ; j++ ){
                    dp[i] = min( dp[i], 1+dp[j] );
                }
            }
        }
        
        return dp[0];
    }
};