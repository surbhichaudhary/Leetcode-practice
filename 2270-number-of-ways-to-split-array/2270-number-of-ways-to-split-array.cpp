class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        vector<long long> lft( n, 0 );
        vector<long long> rgt( n, 0 );
        
        lft[0] = nums[0];
        for( int i = 1; i < n ;i++ ){
            lft[i] = lft[i-1] + nums[i];
        }
        
        rgt[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i-- ){
            rgt[i] = rgt[i+1] + nums[i];
        }
        
        for( int i = 0 ; i < n-1 ; i++ ){
            if( lft[i] >= rgt[i+1] ){
                ans++;
            }
        }
        
        return ans;
    }
};