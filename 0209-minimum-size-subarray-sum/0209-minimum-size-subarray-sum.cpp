class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0, j=0, n = nums.size() , ans = n+1, s=0;
        while( j < n ){
            s += nums[j];
            
            while( s >= target ){
                ans = min( ans, j-i+1);
                s -= nums[i];
                i++;
            }
            
            j++;
            
        }
        
        return ((ans <= n) ? ans : 0 );
    }
};