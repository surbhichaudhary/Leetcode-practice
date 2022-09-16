class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort( nums.begin(), nums.end() );
        long long i=0, j=0, ans = 0, n= nums.size(), s=0;
        
        while( j < n ){
            s += nums[j];
            if( s + k >= nums[j] * (j-i+1) ){
                ans = max( ans, j-i+1 );
            }
            else{
                while( s + k < nums[j] * (j-i+1) ){
                    s -= nums[i];
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};
/*int ans = 1, n = nums.size();
        for( int i = 1 ; i < n; i++ ){
            int mv = k, j = i-1, curr = 1;
            while( j >= 0 && nums[i]-nums[j] <= mv && mv > 0 ){
                if( nums[i] - nums[j] <= mv ){
                    mv -= (nums[i] - nums[j]);
                }
                curr++;
                j--;
            }
            ans = max( ans, curr );
        }*/