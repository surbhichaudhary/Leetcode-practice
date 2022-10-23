class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int d, m, n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            mp[nums[i]]++;
            if( mp[nums[i]] > 1 ){
                d = nums[i];
            }
        }
        
        for( int i = 1 ; i <= n ; i++ ){
            if( !mp.count(i) ){
                m = i;
                break;
            }
        }
        
        vector<int> ans;
        ans.push_back(d);
        ans.push_back(m);
        return ans;
    }
};