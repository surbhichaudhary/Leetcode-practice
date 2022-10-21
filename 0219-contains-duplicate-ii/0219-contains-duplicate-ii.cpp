class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int> > mp;
        for( int i = 0 ; i < nums.size() ; i++ ){
            mp[nums[i]].push_back(i);
            if( mp[nums[i]].size() >= 2  ){
                int n = mp[nums[i]].size(), i1 = mp[nums[i]][n-1], i2 = mp[nums[i]][n-2] ;
                if( abs( i2 - i1 ) <= k ){
                    return true;
                }
            }
        }
        return false;
    }
};