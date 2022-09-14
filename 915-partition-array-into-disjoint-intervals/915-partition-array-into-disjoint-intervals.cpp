class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> max_left(n, INT_MIN );
        vector<int> min_right(n, INT_MAX );
        
        max_left[0] = nums[0];
        min_right[n-1] = nums[n-1];
        
        for( int i = 1 ; i < n ; i++ ){
            max_left[i] = max( max_left[i-1], nums[i] );
        }
        for( int i = n-2 ; i >= 0 ; i-- ){
            min_right[i] = min( min_right[i+1], nums[i] );
        }
        
        for( int i = 1; i < n ;i++ ){
            if( max_left[i-1] <= min_right[i] ){
                return i;
            }
        }
        return 0;
    }
};