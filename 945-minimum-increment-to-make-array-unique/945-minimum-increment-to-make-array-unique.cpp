class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size(), ans=0;
        sort( nums.begin(), nums.end() );
        int mn = nums[0];
        
        for( int i =1; i < n; i++ ){
            if( nums[i] <= mn ){
                int t = nums[i];
                nums[i] += ( mn-t+1 );
                ans += ( mn-t+1 );
            }
            mn = max( mn, nums[i] );
        }
        return  ans;
    }
};
