class Solution {
public:
    
    set<vector<int>> s;
    int n;
    
    void solve( int i, vector<int>& nums){
        if( i >= n ) return;
        if( i == n - 1 ){
            s.insert( nums );
            return;
        }
        
        solve( i+1, nums );
        
        for( int j = i+1 ; j< n ;j++ ){
            swap( nums[i], nums[j] );
            solve( i+1, nums );
            swap( nums[i], nums[j] );
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        s.clear();
        
        solve( 0, nums );
        
        for( auto i : s ){
            ans.push_back(i);
        }
        return ans;
    }
};