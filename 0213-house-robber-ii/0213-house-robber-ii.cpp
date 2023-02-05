class Solution {
public:
    
    int solve( int i, int e, vector<int>& nums, vector<int>& dp ){
        if( i >= e ){
            return 0;
        }
        if( dp[i] != -1 ){
            return dp[i];
        }
        
        int exc = solve( i+1, e, nums, dp );
        int inc = nums[i] + solve( i+2, e, nums, dp );
        
        return dp[i] = max( inc, exc );
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ){
            return nums[0];
        }
        if( n==2 ){
            return max( nums[0], nums[1] );
        }
        
        vector<int> dp1( n, -1);
        vector<int> dp2( n, -1);

        return max( solve( 1, n, nums, dp1), solve(0, n-1, nums, dp2) );
    }
};