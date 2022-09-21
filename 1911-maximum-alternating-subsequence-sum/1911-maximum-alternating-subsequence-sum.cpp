class Solution {
public:
    
    long long solve( int i, int cnt, vector<int>& nums, vector<vector<long long>>& t ){
        if( i >= nums.size() ){
            return 0;
        }
        
        if( t[i][cnt] != -1 ){
            return t[i][cnt];
        }
        
        //not include curr
        long long ans = solve( i+1, cnt, nums, t ), sum = 0;
        //include curr
        if( cnt % 2 == 0 ){
            sum = nums[i];
        }
        else{
            sum -= nums[i];
        }
        ans = max( ans, solve( i+1, cnt^1, nums, t )+sum );
        return t[i][cnt] = ans;
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> t( n+1, vector<long long>( 2, -1) );
        
        return solve( 0, 0, nums, t );
    }
};