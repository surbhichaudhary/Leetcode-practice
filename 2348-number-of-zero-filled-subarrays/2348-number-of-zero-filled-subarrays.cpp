class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, i=0;
        
        while( i < nums.size() ){
            if( nums[i] == 0 ){
                long long j = i, l = 0;
                while( j < nums.size() && nums[j] == 0 ){
                    l++;
                    j++;
                }
                
                ans += ( l*(l+1) )/2;
                i = j+1;
                
            }
            else{
                i++;
            }
        }
        return ans;
    }
};