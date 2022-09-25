class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        for( int i = 0 ; i < nums.size() ; i++ ){
            int rev = 0, n = nums[i];
            while( n > 0 ){
                int r = n%10;
                rev = rev*10 + r;
                n /= 10;
            }
            
            mp[nums[i]-rev]++;
        }
        
        int m = 1000000007, ans = 0;
        for( auto i : mp ){
            long long f = i.second * ( i.second - 1 ) /2 ;
            ans = ( ans%m + f%m )%m;
        }
        return ans;
    }
};