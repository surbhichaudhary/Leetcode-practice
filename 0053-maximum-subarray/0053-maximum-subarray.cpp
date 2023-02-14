class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, cs = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            cs += nums[i];
            mx = max( mx, max( cs, nums[i] ) );
            if( cs < 0 )
                cs = 0;
        }
        
        return mx;
    }
};