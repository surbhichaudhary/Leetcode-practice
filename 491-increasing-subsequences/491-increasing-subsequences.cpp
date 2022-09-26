class Solution {
public:
    
    void solve( int i, vector<int>& nums, vector<int>& curr, map< vector<int>, int>& mp ){
        if( i >= nums.size() ){
            if( curr.size() > 1 ){
                mp[curr]++;
            }
            return;
        }
        
        int n = curr.size();
        
        if( n == 0 || nums[i] >= curr[n-1] ){
            curr.push_back(nums[i]);
            solve( i+1, nums, curr, mp );
            curr.pop_back();
        }
        
        solve( i+1, nums, curr, mp );
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        map< vector<int>, int> mp;
        
        solve( 0, nums, curr, mp );
        
        for( auto i : mp ){
            ans.push_back( i.first );
        }
        
        return ans;
    }
};