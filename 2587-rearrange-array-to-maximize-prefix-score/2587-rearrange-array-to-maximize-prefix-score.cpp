class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort( nums.begin(), nums.end(), greater<int>() );
        
        int n = nums.size(), ans = 0, s= 0, e = n-1;
        vector<long long> pre( n, 0);
        
        pre[0] = nums[0];
        for( int i = 1 ; i <n  ;i++ ){
            pre[i] = pre[i-1] + nums[i];
        }
        
        for( int i = 0 ; i < n ; i++ ){
            if( pre[i] <= 0 ){
                return i;
            }
        }
        return n;
    }
};