class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long n = nums.size(), s=0, q = queries.size();
        for( int i=0 ; i<n ; i++ ){
            if( nums[i]%2 == 0 ){
                s += nums[i];
            }
        }
        
        vector<int> ans(q);
        for( int i=0; i<q; i++ ){
            long long val = queries[i][0], ind = queries[i][1];
            if( nums[ind] % 2 == 0 ){
                s -= nums[ind];
            }
          
            nums[ind] += val;

            if( nums[ind] % 2 == 0 ){
                s += nums[ind];
            }
            
            ans[i] = s;
        }
        
        return ans;
    }
};