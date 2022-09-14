class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> max_left(n, INT_MIN );
        vector<int> min_right(n, INT_MAX );
        
        for( int i = 1 ; i < n ; i++ ){
            max_left[i] = max( max_left[i-1], nums[i-1] );
        }
        for( int i = n-2 ; i > 0 ; i-- ){
            min_right[i] = min( min_right[i+1], nums[i+1] );
        } 
        
        for( int i = 1 ; i < n-1 ; i++ ){
            if( nums[i] > max_left[i] && nums[i] < min_right[i] ){
                ans += 2;
            }
            else if( nums[i] > nums[i-1] && nums[i] < nums[i+1] ){
                ans++;
            }
        }
        return ans;
    }
};