class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        
        int ans = 0, n = nums.size();
        for( int i =0 ;i<n; i++ ){
            int k = i+2;
            for( int j = i+1 ; j < n-1 && nums[i] != 0 ; j++ ){
                while( k < n && nums[i] + nums[j] > nums[k] )
                    k++;
                ans += k - j - 1;
            }
        }
        
        return ans;
    }
};