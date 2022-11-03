class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size(), ans = 0, mf = 0, mx=0;
        
        sort( nums.begin(), nums.end() );
        unordered_map<int, int> mp;
        
        for( int i = n-1 ; i >= 0 ; i-- ){
            int r = nums[i]%space;
            mp[r]++;
           
            if( mp[r] >= mf ){
                mf = mp[r];
                ans = nums[i];
            }
        }
        
        return ans;
    }
};