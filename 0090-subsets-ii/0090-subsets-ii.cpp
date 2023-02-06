typedef vector<int> vi;

class Solution {
public:
    
    void solve( int i, vi& curr, vi& nums, map<vi, int>& mp ){
        if( i>= nums.size() ){
            mp[curr]++;
            return;
        }
        
        solve( i+1, curr, nums, mp );
        curr.push_back( nums[i] );
        solve( i+1, curr, nums, mp );
        curr.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vi, int> mp;
        vector<vector<int>>  ans;
        vi curr;
        sort( nums.begin(), nums.end() );
        
        solve(0, curr, nums, mp);
        
        for( auto i : mp ){
            ans.push_back(i.first);
        }
        
        return ans;
        
    }
};